#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<math.h>
#include<dos.h>

class Chess
{
   public:void chessboard (void);
   public:void piece_position ( int[8][8] );
   public:void place_pieces (int[8][8],int[8][8]);
   public:void move_control (int[8][8],int[],int x1=171,int y1=171,int x2=221, int y2=221);	//specifying default values
   public:void move_piece (int,int,int,int,int[8][8],int[8][8]);
   public:void king_status(int[8][8]);
   public:void messages (int);
   private:void coordinate_manager(int*,int*);
   private:void rubber(int,int,int);
   private:void move_right (int&,int,int&,int,int);
   private:void move_left (int&,int,int&,int,int);
   private:void move_down (int,int&,int,int&,int);
   private:void move_up (int,int&,int,int&,int);
   private:void decolorize_shadow (int,int,int,int);
   private:void draw_pawn(int,int,int,int);
   private:void draw_knight(int,int,int,int);
   private:void draw_bishop(int,int,int,int);
   private:void draw_rook(int,int,int,int);
   private:void draw_king(int,int,int,int);
   private:void draw_queen(int,int,int,int);
   private:int verify_move (int,int,int,int,int[8][8]);
   private:int jump_test (int,int,int,int,int[8][8]);
   private:int move_pawn (int,int,int,int,int,int[8][8],int[8][8],int*);
   private:void update_pawns(int[8][8],int,int,int,int,int);
};


extern int turn = 0;		//global variable

void main (void)
{
	clrscr();

	int positions[8][8] = {0};	//contains positions of all pieces on the board
	int colormap[8][8] = {0};	//contains color with which pieces will be drawn
	int move_info[4];		//contains informations of a piece's (that has been moved) old and new positions	[newx] [newy] [oldx] [oldy]
	int gatekeeper = 0;

	int gdriver = DETECT, gmode;
	initgraph (&gdriver, &gmode, "C:\\TC\\BGI");	//starting graphics engine

	Chess objChess;
	while ( 1 )
	{
		if ( gatekeeper == 0 )
		{
			objChess.chessboard ();				//drawing chessboard
			objChess.piece_position ( positions ); 		//placing pieces (internally)
			objChess.place_pieces ( positions,colormap );	//placing pieces (graphically)
		}
		objChess.messages(0);
		objChess.move_control ( positions,move_info );	//piece to move
		objChess.move_piece ( move_info[0],move_info[1],move_info[2],move_info[3],positions,colormap);	//moves a piece
		objChess.king_status ( positions );

		if ( turn == 0 )
			turn = 1;
		else
			turn = 0;
		gatekeeper++;
	}//end of while

}//end of main function



void Chess::chessboard (void)
{
	clrscr();

	setfillstyle(SOLID_FILL,LIGHTGREEN);	//colours the
	floodfill(320,240,2);            //background

	setlinestyle (SOLID_LINE,1,THICK_WIDTH);	//for thick edge of the board

	setcolor(BLACK);
	int x1=21,y1=21,x2=71,y2=71;
	for (int j=1; j <= 8; j++)
	{
		for (int i=1; i <= 8; i++)
		{
			rectangle(x1,y1,x2,y2);

			if ( j%2 == 0)
				if ( i%2 == 0 )
					setfillstyle (SOLID_FILL, BLACK);	//colouring
				else
					setfillstyle (SOLID_FILL, WHITE);
			else                                      //alternate
				if ( i%2 == 0 )
					setfillstyle (SOLID_FILL, WHITE);
				else                                   //boxes
					setfillstyle (SOLID_FILL, BLACK);

			floodfill (x1+3, y1+3, BLACK);

			x1 += 50;
			x2 += 50;
		}//end of loop (that prints boxes in horizontal)
		x1 = 21;
		x2 = 71;
		y1 += 50;
		y2 += 50;
	}//end of for loop (that prints boxes in vertical)

	setcolor(WHITE);
	setlinestyle (SOLID_LINE,1,THICK_WIDTH);
	setfillstyle (SOLID_FILL, BLACK);		//draws the
	rectangle (473,21,619,91);			//message window
	floodfill (483,25,WHITE);
	setlinestyle (SOLID_LINE,1,NORM_WIDTH);

}//end of chessboard function



void Chess::piece_position ( int positions[8][8] )
{
	enum  {WHITE_PAWN=1, WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP,//specifying constants ranging
			 WHITE_QUEEN, WHITE_KING, BLACK_PAWN, BLACK_ROOK,		//from 1 to 12. e.g., 6 represent white_king
			 BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING};//and 11 represents black_queen


	positions[0][0] = ( positions[7][0] = BLACK_ROOK );
	positions[1][0] = ( positions[6][0] = BLACK_KNIGHT );
	positions[2][0] = ( positions[5][0] = BLACK_BISHOP );
	positions[3][0] = BLACK_QUEEN;
	positions[4][0] = BLACK_KING;
	for ( int xindx=0; xindx < 8; xindx++ )
		positions[xindx][1] = BLACK_PAWN;


	positions[0][7] = ( positions[7][7] = WHITE_ROOK );
	positions[1][7] = ( positions[6][7] = WHITE_KNIGHT );
	positions[2][7] = ( positions[5][7] = WHITE_BISHOP );
	positions[3][7] = WHITE_QUEEN;
	positions[4][7] = WHITE_KING;
	for ( xindx=0; xindx < 8; xindx++ )
		positions[xindx][6] = WHITE_PAWN;

}//end of piece_position function



void Chess::place_pieces (int positions[8][8],int colormap[8][8])
{
	int color, i, j;

	enum Team {BLACK, WHITE};	//specifying constants
	Team turn;			//declaring a variable whose 0 value is equal to BLACK and 1 equal to WHITE

	turn = BLACK;

	for (int y=0; y<8; y++)
		for (int x=0; x<8; x++)
		{
			if ( ((y+1)%2) == 0 )
			{
				if ( ((x+1)%2) == 0 )
					colormap[x][y] = 15;
				else
					colormap[x][y] = 0;
			}
			else
			{
				if ( ((x+1)%2) == 0 )
					colormap[x][y] = 0;
				else
					colormap[x][y] = 15;
			}
		}//end of 'x' for


	for (int Y=0; Y < 8; Y++)
		for (int X=0; X < 8; X++)
		{
			i = X;      //will be sent to
			j = Y;      //coordinate manager

			if ( positions[X][Y] >= 1 && positions[X][Y] <= 6 )
				turn = WHITE;

			color = colormap[X][Y];

			coordinate_manager ( &i,&j );	//converting into screen coordinates

			switch ( positions[X][Y] )
			{
				case	1:
				case	7:    rubber (i,j,color);
								draw_pawn (i, j, turn, color);
								break;
				case	2:
				case	8:    rubber (i,j,color);
								draw_rook (i, j, turn, color);
								break;
				case	3:
				case	9:    rubber (i,j,color);
								draw_knight (i, j, turn, color);
								break;
				case	4:
				case	10:   rubber (i,j,color);
								draw_bishop (i, j, turn, color);
								break;
				case	5:
				case	11:   rubber (i,j,color);
								draw_queen (i, j, turn, color);
								break;
				case	6:
				case	12:   rubber (i,j,color);
								draw_king (i, j, turn, color);
								break;
			}//end of draw_piece switch structure
		}//end of loop with X

}//end of draw_pieces function



void Chess::coordinate_manager (int *x, int *y)
{
	if (*x >= 0 && *x <= 7)		 //to differentiate if the coordinates are to be changed according to board or to the screen
	{
		*x = (*x * 50) + 21;		 //row-no = (row-no * horizontal lenght of a box) + distance from left side of screen
		*y = (*y * 50) + 21;     //converting board coordinates into screen coodinates
	}
	else
	{
		*x = (*x - 21) / 50;		 //converting screen coordinates into board coordinates
		*y = (*y - 21) / 50;
	}

}//end of coordinate_manager



void Chess::rubber(int x,int y, int color)
{
	int tempcolor=0;
	if ( color == 0 )
		tempcolor = 15;
	setfillstyle (SOLID_FILL,tempcolor);
	bar (x+10,y+10,x+40,y+40);		//rubbing the previous contents


}//end of rubber box



void Chess::draw_pawn (int x,int y,int turn,int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle (CLOSE_DOT_FILL,WHITE);
	floodfill (x+32,y+32,color);

	if (turn == 0)
		setfillstyle (SOLID_FILL,BLACK);
	else
		setfillstyle (SOLID_FILL,WHITE);

	setcolor(LIGHTGRAY);
	circle (x+25,y+25,7);
	floodfill (x+25,y+25,LIGHTGRAY);

}//end of draw_pawn function



void Chess::draw_rook (int x,int y,int turn,int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle (INTERLEAVE_FILL,WHITE);
	floodfill (x+25,y+25,color);

	if (turn == 0)
		setfillstyle (SOLID_FILL,BLACK);
	else
		setfillstyle (SOLID_FILL,WHITE);

	setcolor (LIGHTGRAY);
	bar (x+16,y+14,x+23,y+22);		//upper left
	bar (x+27,y+14,x+34,y+22);    //upper right
	bar (x+27,y+28,x+34,y+36);    //lower right
	bar (x+16,y+28,x+23,y+36);    //lower left

}//end of draw_rook function



void Chess::draw_knight (int x,int y,int turn,int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle (XHATCH_FILL,WHITE);
	floodfill (x+25,y+25,color);

	if (turn == 0)
		setfillstyle (SOLID_FILL,BLACK);
	else
		setfillstyle (SOLID_FILL,WHITE);

	setcolor (LIGHTGRAY);
	line (x+18,y+16,x+32,y+16);	//top
	line (x+18,y+16,x+18,y+27);   //left
	line (x+32,y+16,x+32,y+27);	//right
	arc (x+25,y+28,179,270,7);
	arc (x+25,y+28,270,0,7);
	floodfill(x+25,y+25,LIGHTGRAY);

	if ( turn == 0 )
		color = 15;
	else
		color = 0;

	setcolor (color);
	line (x+22,y+23,x+28,y+23);
	line (x+25,y+19,x+25,y+31);

}//end of draw_knight function



void Chess::draw_bishop (int x,int y,int turn,int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle (INTERLEAVE_FILL,WHITE);
	floodfill (x+25,y+25,color);

	if (turn == 0)
		setcolor(BLACK);
	else
		setcolor(WHITE);

	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line (x+16,y+22,x+34,y+22);
	line (x+25,y+15,x+25,y+35);
	setlinestyle(SOLID_LINE,1,NORM_WIDTH);

}//end of draw_bishop function



void Chess::draw_queen (int x,int y,int turn,int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle (WIDE_DOT_FILL,WHITE);
	floodfill (x+25,y+25,color);

	setcolor (LIGHTGRAY);
	line (x+15,y+29,x+18,y+19);
	line (x+18,y+19,x+22,y+27);
	line (x+22,y+27,x+24,y+19);
	line (x+25,y+19,x+27,y+27);
	line (x+27,y+27,x+30,y+19);
	line (x+31,y+19,x+33,y+29);
	arc (x+24,y+23,207,347,10);

	if (turn == 0)
		setfillstyle (SOLID_FILL,BLACK);
	else
		setfillstyle (SOLID_FILL,WHITE);

	floodfill(x+25,y+24,LIGHTGRAY);
}//end of draw_queen function



void Chess::draw_king (int x,int y,int turn, int color)
{
	setcolor (color);
	rectangle (x+10,y+10,x+40,y+40);
	setfillstyle(WIDE_DOT_FILL,WHITE);
	floodfill(x+25,y+25,color);

	setcolor (LIGHTGRAY);
	line (x+18,y+31,x+20,y+18);
	line (x+20,y+18,x+22,y+26);
	line (x+22,y+26,x+24,y+18);
	line (x+24,y+18,x+26,y+26);
	line (x+26,y+26,x+28,y+18);
	line (x+28,y+18,x+30,y+31);
	arc (x+24,y+19,242,300,15);

	if (turn == 0)
		setfillstyle (SOLID_FILL,BLACK);
	else
		setfillstyle (SOLID_FILL,WHITE);

	floodfill(x+24,y+21,LIGHTGRAY);

	if ( turn == 0 )
		color = 15;
	else
		color = 0;

	setcolor(color);
	line (x+24,y+31,x+24,y+25);
	line (x+22,y+27,x+26,y+27);
}//end of draw_king function



void Chess::move_control (int positions[8][8],int move_info[],int x1,int y1,int x2, int y2)
{

	int call=0, x, y;
	int color = 2;
	static int xx1=x1,yy1=y1,xx2=x2,yy2=y2;	//to remove the image

	setcolor(color);
	setlinestyle (SOLID_LINE,1,THICK_WIDTH);
	rectangle(x1,y1,x2,y2);			//draws the box in its initial position as specified by the default values

	do
	{
		char detect_zero,direction;

		detect_zero = getch();

		if ( detect_zero != 27 && detect_zero == 0)		//avoiding the escape key
		{
			direction = getch();

			switch ( direction )
			{
				case	77:   move_right (x1,y1,x2,y2,color);
								break;
				case	80:	move_down (x1,y1,x2,y2,color);
								break;
				case	75:	move_left (x1,y1,x2,y2,color);
								break;
				case	72:	move_up (x1,y1,x2,y2,color);
								break;
				default :   messages ( 4 );
			}//end of switch
		}//end of 'avoiding escape key' if structure

		color = 2;
		setcolor(color);	//changing color back to 2 because it is turn 0 after the switch structure
		rectangle(x1,y1,x2,y2);


		x = x1;	//making copies
		y = y1;  //to send to coordinate manager

		if ( detect_zero == 27 )		//exiting on escape key
			exit(1);

		if ( detect_zero == 13 )		//detecting enter key
		{
			coordinate_manager( &x,&y );
			if ( call == 0 )
			{
				color = 4;
				setcolor(color);                  //leavs an image
				rectangle(x1,y1,x2,y2);       //on the selected box
				xx1=x1, xx2=x2, yy1=y1, yy2=y2;	//updating values

				if ( verify_move (x,y,turn,call,positions) == 0 )
				{
					color = 2;
					messages ( 1 );
					setcolor(color);
					rectangle(x1,y1,x2,y2);
				}
				else
				{
					call = 1;
					move_info[2] = x;
					move_info[3] = y;
				}
			}

			else
			{
				setcolor (0);
				rectangle(xx1,yy1,xx2,yy2);
				rectangle(x1,y1,x2,y2);

				if ( verify_move (x,y,turn,call,positions) == 0 )
				{
					messages ( 2 );
					call = 0;
				}
				else
				{
					move_info[0] = x;
					move_info[1] = y;
					setlinestyle(SOLID_LINE,1,NORM_WIDTH);
					break;
				}
			}//end of else
		}//end of if that detects enter key
	}//end of while loop	that controls the box movement
	while (1);

}//end of move_control function


void Chess::move_right (int &x1,int y1,int &x2,int y2,int color)		//accepting as refrence variables
{
	if ( x2 <= 371 )		//preventing the box to go out of the board
	{
		if ( color == 2 )
			decolorize_shadow (x1,y1,x2,y2);		//preventing the image from decolorizing
		x1 += 50;
		x2 += 50;
	}

}//end of move_left function


void Chess::move_down (int x1,int &y1,int x2,int &y2,int color)
{
	if ( y2 <= 371 )
	{
		if ( color == 2 )
			decolorize_shadow (x1,y1,x2,y2);
		y1 += 50;
		y2 += 50;
	}
}//end of move_down function


void Chess::move_left (int &x1,int y1,int &x2,int y2,int color)
{
	if ( x1 > 21 )
	{
		if ( color == 2 )
			decolorize_shadow (x1,y1,x2,y2);
		x1 -= 50;
		x2 -= 50;
	}
}//end of move_left function


void Chess::move_up (int x1,int &y1,int x2,int &y2,int color)
{
	if ( y1 > 21)
	{
		if ( color == 2 )
			decolorize_shadow (x1,y1,x2,y2);
		y1 -= 50;
		y2 -= 50;
	}
	color = 1;
}//end of move_up function


void Chess::decolorize_shadow (int x1,int y1,int x2,int y2)
{
	setcolor (0);
	rectangle (x1,y1,x2,y2);
}//end of decolorize_shadow



int Chess::verify_move (int x,int y,int turn,int call,int positions[8][8])
{
	int pid=0;

	static int knight_check;	//used later to aviod calling jump_test function
	static int oldx,oldy;		//stores x,y from 1st call to this function
	static int copy_array = 0;
	static int pawn_positions[8][8] = {0};


	if ( copy_array == 0 )
	{
		int pid = 1;
		for (int j=0; j<8; j++)
			for (int i=0; i<8; i++)
				if ( positions[i][j] == 1 || positions[i][j] == 7 )
				{
					pawn_positions[i][j] = pid;	//pawn ID
					pid++;
				}
	copy_array = 1;	//so that pawn_positions is not re-copied next time
	}

	if ( call == 0 )
	{
		oldx = x;
		oldy = y;   //storing old values for later use

		if ( positions[x][y] == 0 )
			return 0;			//invalid box

		else if ( turn == 0 )
			if ( positions[x][y] >= 7 && positions[x][y] <= 12 )
			{
				if ( positions[x][y] == 9 )
					knight_check = 1;		//black knight found
				else
					knight_check = 0;		//black knight not found
				return 1;		//valid piece
			}
			else
				return 0;		//invalid piece

		else
			if ( positions[x][y] >= 1 && positions[x][y] <= 6 )
			{
				if ( positions[x][y] == 3 )
					knight_check = 1;		//white knight found
				else
					knight_check = 0;		//white knight not found
				return 1;
			}
			else
				return 0;
	}//end of first call if structure

	else
	{
		switch ( positions[oldx][oldy] )
		{
			case	1:
			case	7:    if ( move_pawn(oldy,y,oldx,x,turn,positions,pawn_positions,&pid) )
								break;
							else
								return 0;
			case	2:
			case	8:		if ( oldx!=x && oldy==y )
								break;
							else if ( oldy!=y && oldx==x )
								break;
							else
								return 0;
			case	3:
			case	9:    if ( abs(oldx-x)==2 && abs(oldy-y)==1 )
								break;
							else if ( abs(oldx-x)==1 && abs(oldy-y)==2 )
								break;
							else
								return 0;
			case	4:
			case	10:   if ( abs(oldx-x) == abs(oldy-y) )
								break;
							else
								return 0;
			case	5:
			case	11:   if ( oldx!=x && oldy==y )
								break;
							else if ( oldx==x && oldy!=y )
								break;
							else if ( abs(oldx-x) == abs(oldy-y) )
								break;
							else
								return 0;
			case	6:
			case	12:   if ( abs(oldx-x) == 1 )
								break;
							else if ( abs(oldy-y) == 1 )
								break;
							else
								return 0;
		}//end of switch

		if ( positions[x][y] == 0 )
		{
			if ( knight_check != 1 )
			{
				if ( jump_test(oldx,oldy,x,y,positions) )
				{
					update_pawns(pawn_positions,oldx,oldy,x,y,pid);
					return 1;
				}
				else
					return 0;
			}//end of knight check
			else
				return 1;
		}//end of empty box found

		if ( turn == 0 )
		{
			if ( positions[x][y] >= 1 && positions[x][y] <= 6 )
			{
				if ( knight_check != 1 )
				{
					if ( jump_test(oldx,oldy,x,y,positions) )
					{
						update_pawns(pawn_positions,oldx,oldy,x,y,pid);
						return 1;
					}
					else
						return 0;
				}//end of knight check
				return 1;
			}//end of white piece found
		}//end of black team's turn

		else
		{
			if ( positions[x][y] >= 7 && positions[x][y] <= 12 )
			{
				if ( knight_check != 1 )
				{
					if ( jump_test(oldx,oldy,x,y,positions) )
					{
						update_pawns(pawn_positions,oldx,oldy,x,y,pid);
						return 1;
					}
					else
						return 0;
				}//end of knight check
				return 1;
			}//end of black piece found
		}//end of white team's turn
	}//end of second call if structure

return 0;
}//end of verify_move function



int Chess::jump_test (int oldx,int oldy,int x,int y,int positions[8][8])
{
	int jumps = 0;
	int temp;

	int piece_id = positions[oldx][oldy];	//because the following if structure may change the values of oldx and oldy (used in the switch)

	do
	{
		if ( positions[oldx][oldy]==4 || positions[oldx][oldy]==10 || positions[oldx][oldy]==5 || positions[oldx][oldy]==11 )	//don't want to swap the values in case of left to right diagonal	movements
		{
			if ( (oldx>x) && (oldy<y) )
				break;									//breaking out in case of left
			else if ( (oldx<x) && (oldy>y) )
				break;                           //to right diagonal movement
		}

		if ( positions[oldx][oldy]!=1 && positions[oldx][oldy]!=7 )	//excluding pawns because they work differently
		{
			if ( oldx < x )      //storing larger value in oldx & oldy to simplify the following switch structure
			{
				temp = oldx;
				oldx = x;
				x = temp;
			}
			if ( oldy < y )
			{
				temp = oldy;
				oldy = y;
				y = temp;
			}
		}
		break;
	}
	while ( 1 );	//the loop is used only because break statement was required


	switch ( piece_id )
	{
		case	1:    while ( oldy>y && oldx==x)
						{
							if ( positions[x][oldy-1] != 0 )
								jumps++;
							oldy--;
						}break;
		case	7:    while ( oldy<y && oldx==x)
						{
							if ( positions[x][oldy+1] != 0 )
								jumps++;
							oldy++;
						}break;
		case	2:
		case	8:		while ( oldx > x+1 )
						{
							if ( positions[oldx-1][y] != 0 )
								jumps++;
							oldx--;
						}
						while ( oldy > y+1 )
						{
							if ( positions[x][oldy-1] != 0 )
								jumps++;
							oldy--;
						}break;
		case	4:
		case	10:   while ( (oldx>x+1) && (oldy>y+1) )
						{
							if ( positions[oldx-1][oldy-1] != 0 )
							{
								jumps++;
								break;
							}
							oldx--;
							oldy--;
						}//end of while
						while ( (oldx<x-1) && (oldy>y+1) )
						{
							if ( positions[oldx+1][oldy-1] != 0 )
								jumps++;
							oldx++;
							oldy--;
						}//end of while
						while ( (oldx>x+1) && (oldy<y-1) )
						{
							if ( positions[oldx-1][oldy+1] != 0 )
								jumps++;
							oldx--;
							oldy++;
						}//end of while
						break;
		case	5:
		case	11:   while ( (oldx>x+1) && (oldy==y) )
						{
							if ( positions[oldx-1][y] != 0 )
								jumps++;
							oldx--;
						}
						while ( (oldy>y+1) && (oldx==x) )
						{
							if ( positions[x][oldy-1] != 0 )
								jumps++;
							oldy--;
						}
						while ( (oldx>x+1) && (oldy>y+1) )
						{
							if ( positions[oldx-1][oldy-1] != 0 )
								jumps++;
							oldx--;
							oldy--;
						}
						while ( (oldx<x-1) && (oldy>y+1) )
						{
							if ( positions[oldx+1][oldy-1] != 0 )
								jumps++;
							oldx++;
							oldy--;
						}//end of while
						while ( (oldx>x+1) && (oldy<y-1) )
						{
							if ( positions[oldx-1][oldy+1] != 0 )
								jumps++;
							oldx--;
							oldy++;
						}//end of while
						break;
	}//end of switch

	if ( jumps == 0 )
		return 1;

return 0;
}//end of jump_test function




int Chess::move_pawn (int oldy,int y,int oldx,int x,int turn,int positions[8][8],int pawn_positions[8][8],int *pid)
{
	static int firstmove[16] = {0};

	*pid =  pawn_positions[oldx][oldy];

	if ( turn == 0 )
	{
		if ( ((y-oldy)==1 || (y-oldy)==2) && oldx==x )
		{
			if ( (firstmove[*pid-1]==0) || (firstmove[*pid-1]!=0 && (y-oldy)==1) )
				if ( jump_test(oldx,oldy,x,y,positions) )
				{
					firstmove[*pid-1] = 1;
					return 1;
				}
			else if ( (y-oldy) == 1 )
				return 1;
		}

		else if ( (y-oldy)==1 && abs(oldx-x)==1 )
		{
			if ( positions[x][y]>=1&&positions[x][y]<=6&&positions[x][y]!=0 )
			{
				firstmove[*pid-1] = 1;
				return 1;
			}
		}

		else
			return 0;
	}//black end

	else
	{
		if ( ((oldy-y)==1 || (oldy-y)==2) && oldx==x )
		{
			if ( (firstmove[*pid-1]==0) || (firstmove[*pid-1]!=0 && (oldy-y)==1) )
				if ( jump_test(oldx,oldy,x,y,positions) )
				{
					firstmove[*pid-1] = 1;
					return 1;
				}
			else if ( (oldy-y) == 1 )
				return 1;
		}

		else if ( (oldy-y)==1 && abs(oldx-x)==1 )
		{
			if ( positions[x][y]>=7&&positions[x][y]<=12 )
			{
					firstmove[*pid-1] = 1;
					return 1;
			}
		}

		else
			return 0;
	}//white end

return 0;
}//end of move_pawn function



void Chess::update_pawns (int pawn_positions[8][8],int oldx,int oldy,int x,int y,int pid)
{
	for (int j=0; j<8; j++)
		for (int i=0; i<8; i++)
			if ( pawn_positions[i][j] == pid )
			{
				pawn_positions[x][y] = pid;
				pawn_positions[oldx][oldy] = 0;
				break;
			}
}//end of update_pawns function



void Chess::move_piece (int x,int y,int oldx,int oldy,int positions[8][8],int colormap[8][8])
{
	positions[x][y] = positions[oldx][oldy];	//moving a piece internally

	int i = oldx;
	int j = oldy;
	int color;

	for (int count=0; count<2; count++)			//moving graphically
	{
		color = colormap[i][j];

/*		if ( count == 0 )            	//to rub a piece from its
		{                             //old position
			if ( colormap[i][j] == 1 )
				color = 15;
			else
				color = 1;
		}*/

		switch ( positions[i][j] )
		{
			case	1:
			case	7:    coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_pawn(i,j,turn,color);
							break;
			case	2:
			case	8:		coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_rook(i,j,turn,color);
							break;
			case	3:
			case	9:		coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_knight(i,j,turn,color);
							break;
			case	4:
			case	10:   coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_bishop(i,j,turn,color);
							break;
			case	5:
			case	11:   coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_queen(i,j,turn,color);
							break;
			case	6:
			case	12:   coordinate_manager( &i,&j );
							rubber (i,j,color);
							if ( count )
								draw_king(i,j,turn,color);
							break;
		}//end of switch
		i = x;
		j = y;
		positions[oldx][oldy] = 0;		//rubbing a piece internally
	}//end of if

}//end of move-piece function


void Chess::king_status (int positions[8][8])
{
	int king=0;

	if ( turn == 0 )
	{
		for (int y=0; y<8; y++)
		{
			for (int x=0; x<8; x++)
				if ( positions[x][y] == 6 )
				{
					king = 1;
					break;
				}
			if ( x != 8 )//checking if upper break was executed
				break;
		}
		if ( king == 0 )
		{
			messages ( 3 );
			getch();
			exit(1);
		}
	}//black end

	else
	{
		for (int y=0; y<8; y++)
		{
			for (int x=0; x<8; x++)
				if ( positions[x][y] == 12 )
				{
					king = 1;
					break;
				}
			if ( x != 8 )
				break;
		}
		if ( king == 0 )
		{
			messages ( 4 );
			getch();
			exit(1);
		}
	}//white end
}//end of king_status function


void Chess::messages ( int msgid )
{
	gotoxy (61,5);

	switch ( msgid )
	{
		case	0:    gotoxy(63,3);
						if ( turn == 0 )
							cout<<"BLACK'S TURN";
						else
							cout<<"WHITE'S TURN";
						break;
		case	1:    cout<<"COULDN'T SELECT";
						break;
		case	2:		cout<<" ILLEGAL MOVE";
						break;
		case	3:		cout<<"  WHITE LOST";
						break;
		case	4:		cout<<"  BLACK LOST";
						break;
		case	5:		cout<<"   CAN'T DO";
						break;

	}//end of switch

	if ( msgid != 0 )
	{
		delay (1000);
		gotoxy (61,5);
		textcolor (0);
		cout<<"                 ";
	}

}//end of msgind function