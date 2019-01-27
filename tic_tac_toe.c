#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char board[3][3];
void display_board(char*,char*);
int generate_pos(int);
int choose_pos(int,char);
int check();
int can_player_win();
int can_computer_win();
void display_board(char *p1,char *p2)
{
    system("cls");
    printf("%s vs %s\n",p1,p2);
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%c| ",board[i][j]);
        }
        printf("%c ",board[i][j]);
        printf("\n");
        if(i<2)
        for(k=0;k<7;k++)
        printf("-");
        printf("\n");
    }
}
int generate_pos(int count)
{
    int x,y;
    if(count)
    {
        if(can_player_win()==1)
            return;
        else if(can_computer_win()==1)
            return;
    }
    x=(rand()%(3-1))+(1),y=(rand()%(3-1))+(1);
    //srand(time(NULL));
    if(board[x][y]=='O'||board[x][y]=='X')
        generate_pos(count);
    else
    {
        board[x][y]='X';
        return;
    }
}
int choose_pos(int pos,char c)
{
    switch(pos)
    {
        case 1:
        {
            if(board[0][0]=='O'||board[0][0]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[0][0]=c;
            break;
        }
        case 2:
        {
            if(board[0][1]=='O'||board[0][1]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[0][1]=c;
            break;
        }
        case 3:
        {
            if(board[0][2]=='O'||board[0][2]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[0][2]=c;
            break;
        }
        case 4:
        {
            if(board[1][0]=='O'||board[1][0]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[1][0]=c;
            break;
        }
        case 5:
        {
            if(board[1][1]=='O'||board[1][1]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[1][1]=c;
            break;
        }
        case 6:
        {
            if(board[1][2]=='O'||board[1][2]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[1][2]=c;
            break;
        }
        case 7:
        {
            if(board[2][0]=='O'||board[2][0]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[2][0]=c;
            break;
        }
        case 8:
        {
            if(board[2][1]=='O'||board[2][1]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[2][1]=c;
            break;
        }
        case 9:
        {
            if(board[2][2]=='O'||board[2][2]=='X')
            {
                printf("INVALID MOVE\n");
                return 1;
            }
            board[2][2]=c;
            break;
        }
    }
    return 0;
}
int check()
{
    int p1,p11,p2,p22,i,j;
    for(i=0;i<3;i++)
    {
        p1=0,p11=0,p2=0,p22=0;
        for(j=0;j<3;j++)
        {
            if(board[j][i]=='X')
            {
             p1++;
            }
            else if(board[j][i]=='O')
            {
                p2++;
            }
            if(board[i][j]=='X')
            {
                p11++;
            }
            else if(board[i][j]=='O')
            {
                p22++;
            }
        }
        if((p1==3||p11==3))
        {
            return 1;
        }
        else if(p2==3||p22==3)
        {
            return 2;
        }
    }
    if((board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X')||(board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X'))
    {
      return 1;
    }
    if((board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O')||(board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O'))
    {
      return 2;
    }
    return 3;
}
int main()
{
    int i,j;
    char player1[100],player2[100];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
    int count=0;
    int Number_of_players,pos;
    int x,y,com_count=1;
    printf("Enter number of players either 1 or 2\n");
    scanf("%d",&Number_of_players);
    if(Number_of_players==1)
    {
        printf("Enter your name\n");
        scanf("%s",player2);
        display_board("Computer",player2);
        srand(time(NULL));
        while(count!=8)
        {
         generate_pos(com_count);
          com_count++;
          count++;
         display_board("Computer",player2);
         if(com_count>=2)
         {
             if(check()==1)
             {
                printf("COMPUTER WINS\n");
                return;
             }
         }
         here :
         printf("Enter pos to place O\n");
         scanf("%d",&pos);
         if(choose_pos(pos,'O')==1)
            goto here;
         count++;
         display_board("Computer",player2);
         if(count>=5)
         {
            if(check()==2)
            {
             printf("YOU WIN\n");
             return;
            }
         }
        }
        if(can_computer_win()==1)
        {
         display_board("Computer",player2);
         printf("COMPUTER WINS\n");
        }
        else
        {
          printf("GAME DRAWN\n");
        }
    }
    else
    {
        int choice;
        char select[1];
        printf("Enter name of player 1\n");
        scanf("%s",player1);
        fflush(stdin);
        printf("Enter name of player 2\n");
        scanf("%s",player2);
        printf("Press 1 if %s wants start and Press 2 if %s wants to start\n",player1,player2);
        scanf("%d",&choice);
        printf("You want to start with O or X\n");
        scanf("%s",select);
        while(count!=8)
        {
         where:
         printf("Enter pos to place %c\n",select[0]);
         scanf("%d",&pos);
         if(choose_pos(pos,select[0])==1)
            goto where;
            display_board(player1,player2);
            count++;
            if(check()==1)
            {
                if(choice==1)
                {
                 printf("%s wins",player1);
                 return;
                }
                else
                    {
                        printf("%s wins\n",player2);
                        return;
                    }
            }
            there:
            if(select[0]=='X')
            {
                printf("Enter pos to place O\n");
                scanf("%d",&pos);
                if(choose_pos(pos,'O')==1)
                goto there;
                count++;
            }
            else
            {
                printf("Enter pos to place X\n");
                scanf("%d",&pos);
                if(choose_pos(pos,'X')==1)
                goto there;
                count++;
            }
            display_board(player1,player2);
            if(check()==2)
            {
                if(choice==1)
                {
                    printf("%s wins",player2);
                    return;
                }
                else
                    {
                        printf("%s wins\n",player1);
                        return;
                    }
            }
        }
        if(can_computer_win()==1)
        {
         display_board(player1,player2);
         if(choice==1)
         printf("%s wins\n",player1);
         else
            printf("%s wins\n",player2);
        }
        else
        printf("Game drawn\n");
    }
}
int can_player_win()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]='O';
                if(check()==2)
                {
                    board[i][j]='X';
                    return 1;
                }
                else
                {
                    board[i][j]=' ';
                }
            }
        }
    }
    return 0;
}
int can_computer_win()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]='X';
                if(check()==1)
                {
                    return 1;
                }
                else
                {
                    board[i][j]=' ';
                    return 0;
                }
            }
        }
    }
    return 0;
}
