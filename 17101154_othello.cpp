#include <bits/stdc++.h>
using namespace std;

int board[8][8];
bool end_game=false;
int bcount=0, wcount=0;

void init();
void printBoard();
void player_move(int c_player);
bool isValidInput(int a, int b, int op);
bool isFull();

//all directional checker functions
bool isValidLeft(int player, int opponent, int a, int b);
bool isValidRight(int player, int opponent, int a, int b);
bool isValidUp(int player, int opponent, int a, int b);
bool isValidDown(int player, int opponent, int a, int b);
bool isValidUpperLeft(int player, int opponent, int a, int b);
bool isValidUpperRight(int player, int opponent, int a, int b);
bool isValidLowerLeft(int player, int opponent, int a, int b);
bool isValidLowerRight(int player, int opponent, int a, int b);

//All direction fill
void fillLeft(int player, int opponent, int a, int b);
void fillRight(int player, int opponent, int a, int b);
void fillUp(int player, int opponent, int a, int b);
void fillDown(int player, int opponent, int a, int b);
void fillUpperLeft(int player, int opponent, int a, int b);
void fillUpperRight(int player, int opponent, int a, int b);
void fillLowerLeft(int player, int opponent, int a, int b);
void fillLowerRight(int player, int opponent, int a, int b);


int main()
{
    init();

    for(int player=1; ; player++)
    {
        if(end_game or isFull())
        {
            printf("Game Over\n");

            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    if(board[i][j]==0)
                        wcount++;
                    else if(board[i][j]==1)
                        bcount++;
                }
            }
            cout<<"Black - "<<bcount<<endl;
            cout<<"White - "<<wcount<<endl;
            if(bcount>wcount)
                cout<<"Black won"<<endl;
            else if(bcount<wcount)
                cout<<"White won"<<endl;
            else
                cout<<"TIE"<<endl;


            break;
        }

        player_move(player%2);
    }
}

void player_move(int c_player)
{
    //1 for black
    //0 for white
    int o_player = (c_player+1)%2;

    if(c_player == 0)
        printf("================================================\n                  White's 0 Turn\n================================================\n\n");
    else
        printf("================================================\n                  Black's X Turn\n================================================\n\n");

    printBoard();
    int a, b;
    while(true)
    {
        cin>>a>>b;
        //checking for valid moves
        if(a>7 or a<0 or b>7 or b<0)
        {
            printf("Invalid Move!! Try Again. 1111 \n");
            continue;
        }
        if(!isValidInput(a,b,o_player))
        {
            printf("Invalid Move!! Try Again. 2222\n");
            continue;
        }

        bool isValidMove = false;

        if(isValidLeft(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillLeft(c_player, o_player, a, b);
        }
        if(isValidRight(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillRight(c_player, o_player, a, b);
        }
        if(isValidUp(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillUp(c_player, o_player, a, b);
        }
        if(isValidDown(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillDown(c_player, o_player, a, b);
        }
        if(isValidUpperLeft(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillUpperLeft(c_player, o_player, a, b);
        }
        if(isValidUpperRight(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillUpperRight(c_player, o_player, a, b);
        }
        if(isValidLowerLeft(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillLowerLeft(c_player, o_player, a, b);
        }
        if(isValidLowerRight(c_player, o_player, a, b))
        {
            isValidMove=true;

            fillLowerRight(c_player, o_player, a, b);
        }

        if(isValidMove)
            return;
        end_game=true;
    }

}


bool isValidInput(int a, int b, int op)
{
    if(board[a][b]!=-1)
        return false;
    bool flag = false;
    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            if(i==0 and j==0)
                continue;
            if(board[a+i][b+j]==op)
                flag = true;

        }
    }
    return flag;
}

bool isFull()
{
    int sum=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j]==-1)
                sum++;
        }
    }
    if(sum>0)
        return false;
    else
        return true;
}

void init()
{
    ///-1 for empty
    ///0 for white
    ///1 for black
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            board[i][j]=-1;
        }
    }
    board[3][3] = board[4][4] = 0;
    board[3][4] = board[4][3] = 1;

}

void printBoard()
{

    cout<<"  ";
    for(int i=0; i<8; i++)
        printf(" %d ",i);
    cout<<endl;
    for(int i=0; i<8; i++)
    {
        printf("%d ",i);
        for(int j=0; j<8; j++)
        {
            if(board[i][j]==-1)
                printf(" . ");
            else if(board[i][j] == 0)
                printf(" O ");
            else
                printf(" X ");
        }
        printf("\n");
    }
}

bool isValidLeft(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a][b-1] == player)
        return false;


    for(int y=b-1; y>=0; y--)
    {
        if(board[a][y]==opponent)
            continue;
        else if(board[a][y]==-1)
        {
            flag = false;
            break;
        }
        else if(board[a][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidRight(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a][b+1] == player)
        return false;
    for(int y=b+1; y<8; y++)
    {
        if(board[a][y]==opponent)
            continue;
        else if(board[a][y]==-1)
        {
            flag = false;
            break;
        }
        else if(board[a][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidUp(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a-1][b] == player)
        return false;
    for(int x=a-1; x>=0; x--)
    {
        if(board[x][b]==opponent)
            continue;
        else if(board[x][b] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][b] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidDown(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a+1][b] == player)
        return false;
    for(int x=a+1; x<8; x++)
    {
        if(board[x][b]==opponent)
            continue;
        else if(board[x][b] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][b] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidUpperLeft(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a-1][b-1] == player)
        return false;
    for(int x=a-1, y=b-1; x>=0 && y>=0; x--,y--)
    {
        if(board[x][y]==opponent)
            continue;
        else if(board[x][y] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidUpperRight(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a-1][b+1] == player)
        return false;
    for(int x=a-1, y=b+1; x>=0&&y<8; x--,y++)
    {
        if(board[x][y]==opponent)
            continue;
        else if(board[x][y] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidLowerLeft(int player, int opponent, int a, int b)
{
    bool flag = false;
    if(board[a+1][b-1] == player)
        return false;
    for(int x=a+1, y=b-1; x<0&&y>=0; x++,y--)
    {
        if(board[x][y]==opponent)
            continue;
        else if(board[x][y] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool isValidLowerRight(int player, int opponent, int a, int b)
{
    bool flag = false;

    if(board[a+1][b+1]==player)
        return false;

    for(int x=a+1, y=b+1; x<8 && y<8; x++,y++)
    {
        if(board[x][y]==opponent)
            continue;
        else if(board[x][y] == -1)
        {
            flag = false;
            break;
        }
        else if(board[x][y] == player)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void fillLeft(int player, int opponent, int a, int b) {
    board[a][b]=player;
    for(int y=b-1; y>=0; y--)
    {
        if(board[a][y]==opponent)
        {
            board[a][y]=player;
            continue;
        }
        else if(board[a][y]==-1)
        {
            break;
        }
        else if(board[a][y] == player)
        {
            break;
        }
    }
}

void fillRight(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int y=b+1; y<8; y++)
    {
        if(board[a][y]==opponent)
        {
            board[a][y]=player;
            continue;
        }
        else if(board[a][y]==-1)
        {
            break;
        }
        else if(board[a][y] == player)
        {
            break;
        }
    }
}

void fillUp(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a-1; x>=0; x--)
    {
        if(board[x][b]==opponent)
            board[x][b]=player;
        else if(board[x][b] == -1)
        {
            break;
        }
        else if(board[x][b] == player)
        {
            break;
        }
    }
}

void fillDown(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a+1; x<8; x++)
    {
        if(board[x][b]==opponent)
            board[x][b]=player;
        else if(board[x][b] == -1)
        {
            break;
        }
        else if(board[x][b] == player)
        {
            break;
        }
    }

}

void fillUpperLeft(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a-1, y=b-1; x>=0 && y>=0; x--,y--)
    {
        if(board[x][y]==opponent)
            board[x][y]=player;
        else if(board[x][y] == -1)
        {
            break;
        }
        else if(board[x][y] == player)
        {
            break;
        }
    }
}

void fillUpperRight(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a-1, y=b+1; x>=0&&y<8; x--,y++)
    {
        if(board[x][y]==opponent)
            board[x][y]=player;
        else if(board[x][y] == -1)
        {
            break;
        }
        else if(board[x][y] == player)
        {
            break;
        }
    }

}

void fillLowerLeft(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a+1, y=b-1; x<0&&y>=0; x++,y--)
    {
        if(board[x][y]==opponent)
            board[x][y]=player;
        else if(board[x][y] == -1)
        {
            break;
        }
        else if(board[x][y] == player)
        {
            break;
        }
    }

}

void fillLowerRight(int player, int opponent, int a, int b)
{
    board[a][b]=player;
    for(int x=a+1, y=b+1; x<8 && y<8; x++,y++)
    {
        if(board[x][y]==opponent)
            board[x][y]=player;
        else if(board[x][y] == -1)
        {
            break;
        }
        else if(board[x][y] == player)
        {
            break;
        }
    }

}
