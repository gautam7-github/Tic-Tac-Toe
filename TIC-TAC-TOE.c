#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>



void introduction()
{
    printf("\n\t-Instructions to play-\n");
    printf("\n\n\tT I C  T A C  T O E");
    printf("\n\n\n\n\t     |     |     ");
    printf("\n\t  1  |  2  |  3  ");
    printf("\n\t_____|_____|_____");
    printf("\n\t     |     |     ");
    printf("\n\t  4  |  5  |  6  ");
    printf("\n\t_____|_____|_____");
    printf("\n\t     |     |     ");
    printf("\n\t  7  |  8  |  9  ");
    printf("\n\t     |     |     ");



    printf("\n\n Use 1 to 9 numbers to play your turn");
    printf("\n\n\t\t\t\t\tcreated by Parshant\n\n");
    system("pause");
    system("cls");
}



///  UTILITY FUNCTIONS ---------------------------------

void board(char game[])// Displaying BOARD
{
    printf("\n\n\tT I C  T A C  T O E");
    printf("\n\n\n\n\t     |     |     ");
    printf("\n\t  %c  |  %c  |  %c  ",game[0],game[1],game[2]);
    printf("\n\t_____|_____|_____");
    printf("\n\t     |     |     ");
    printf("\n\t  %c  |  %c  |  %c  ",game[3],game[4],game[5]);
    printf("\n\t_____|_____|_____");
    printf("\n\t     |     |     ");
    printf("\n\t  %c  |  %c  |  %c  ",game[6],game[7],game[8]);
    printf("\n\t     |     |     ");
}

char get_random(char choice_history[]) // to get random value to insert in the cells
{
    int random;
    char random_char;
    int flag=0;

    srand(time(0));



    do{
        flag=0;
        random=rand()%9+1;
        random_char=(char)random+48;
        for(int i=0;i<9;i++)
        {
            if(choice_history[i]==random_char)
            {
                flag=1;
            }
        }
    }while(flag==1);

    return random_char;
}

char if_wins(int turn_n,char choice[]) // insert in the winning cell
{
    int i,j,k;
    int index,flag;
    char index_in_char;
    for(i=turn_n-3;i>=0;i-=2)
    {
        for(j=turn_n-3;j>=0;j-=2)
        {

            if(i==j)
            {
                continue;
            }
            index=(int)(choice[i]+choice[j])-96;
            index=15-index;

            if(index>=1&&index<=9)
            {
                index_in_char=(char)index+48;
                flag=0;
                for(k=0;k<turn_n-1;k++)// check if index_in_char occupied or not
                {
                    if(choice[k]==index_in_char)
                    {
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    return index_in_char; // bingo
                }
            }

        }
    }

    return 'N'; // no one is winning
}

char check_for_user_valid(char game[],char choice) // to check the invalid entries by user
{
    char choice_converted;

    int index1=(int)choice-48;
    int index2;

    // to convert the entered choice to their correspondings
    switch(index1)
    {
    case 1:
            index2=2;
        break;
    case 2:
            index2=9;
        break;
    case 3:
            index2=4;
        break;
    case 4:
            index2=7;
        break;
    case 5:
            index2=5;
        break;
    case 6:
            index2=3;
        break;
    case 7:
            index2=6;
        break;
    case 8:
            index2=1;
            break;
    case 9:
            index2=8;
        break;

    default:
        printf("\n\n\tInvalid Entry : ");
        return 'N';
        break;
    }

    if(game[index1-1]=='X' || game[index1-1]=='0')
    {
        printf("\n\n\tError! Space occupied : ");
        return 'N';
    }

    game[index1-1]='0';
    choice_converted=(char)index2+48;
    return choice_converted;

}

int change_index_CPU(char choice) // to change the index of CPU's turn
{
    int index;
    // to convert the entered choice to their correspondings
    switch(choice)
    {
 case '1':
    index=8;
    break;

 case '2':
    index=1;
    break;

 case '3':
    index=6;
    break;

 case '4':
    index=3;
    break;

 case '5':
    index=5;
    break;

 case '6':
    index=7;
    break;

 case '7':
    index=4;
    break;

 case '8':
    index=9;
    break;

 case '9':
    index=2;
    break;
    }

    return index;
}

int check(int turn_n,char choice_history[],char ch) // secret recipe
{
    char choice_In_char;
    int i;
    int char1=(int)choice_history[turn_n-1]-48;
    int char2=(int)ch-48;


    for(i=0;i<9;i++)
    {
        if(choice_history[i]==ch)
        {
            return 0;
        }
    }

    int choice=15-(char1+char2);

    if(ch==((char)choice+48))
    {
        return 0; // test fails
    }


    if(choice>=1&&choice<=9)
    {
        choice_In_char=(char)choice+48;
        for(i=0;i<9;i++)
        {
            if(choice_history[i]==choice_In_char)
            {
                return 0; // it fails
            }
        }
            return 1; // it succeed

    }
    return 0;// it fails

}

int gameover(char game[])// GAME OVER
{
    int flag=0;
    int i;

    //checking who wins

    for(i=0;i<3;i++)
    {
        if(game[0+(3*i)]!=' ' &&  game[0+(3*i)]==game[1+(3*i)] && game[1+(3*i)]==game[2+(3*i)]) // checking rows
        {
            flag=1;
        }

        if(game[0+i]!=' ' && game[0+i]==game[3+i]&&game[3+i]==game[6+i])    //checking columns
        {
            flag=1;
        }
    }

    //checking diagonals
    if(game[0]!=' ' && game[0]==game[4] && game[4]==game[8])
    {
        flag=1;
    }

    if(game[2]!=' ' && game[2]==game[4] && game[4]==game[6])
    {
        flag=1;
    }

    if(flag==1)//someone wins
    {
        return 1;
    }

    // checking for empty space
    for(i=0;i<9;i++)
    {
        if(game[i]==' ')
        {
            return 0; // continue game
        }
    }

    return 2; // game draw
}

///   UTILITY FUNCION ends------------------------------


/// HARD LEVEL------------------------------------------
char CPU_turn_hard(int turn_n,char game[], char choice[])//CPU's entry for hard level
{
    char CPU[104][7]={{'2','1','4','9','5','6','8'},
{'2','1','5','8','6','4','7'},
{'2','1','6','7','4','5','9'},
{'2','1','6','7','5','4','8'},
{'2','3','4','9','5','6','8'},
{'2','3','4','9','6','5','7'},
{'2','3','5','8','4','6','9'},
{'2','3','6','7','5','4','8'},
{'2','4','6','7','8','1','5'},
{'2','4','7','6','5','3','8'},
{'2','4','8','5','6','1','7'},
{'2','6','4','9','8','3','5'},
{'2','6','8','5','4','3','9'},
{'2','6','9','4','5','1','8'},
{'2','7','4','9','5','6','8'},
{'2','7','4','9','8','3','5'},
{'2','7','5','8','4','6','9'},
{'2','7','5','8','9','1','4'},
{'2','7','9','4','5','1','8'},
{'2','8','4','9','6','5','7'},
{'2','8','6','7','4','5','9'},
{'2','9','5','8','6','4','7'},
{'2','9','5','8','7','3','6'},
{'2','9','6','7','5','4','8'},
{'2','9','6','7','8','1','5'},
{'2','9','7','6','5','3','8'},
{'4','1','2','9','5','8','6'},
{'4','1','5','6','8','2','3'},
{'4','1','8','3','2','5','9'},
{'4','1','8','3','5','2','6'},
{'4','2','3','8','5','7','6'},
{'4','2','6','5','8','1','3'},
{'4','2','8','3','6','1','5'},
{'4','3','2','9','5','8','6'},
{'4','3','2','9','6','7','5'},
{'4','3','5','6','2','8','9'},
{'4','3','5','6','9','1','2'},
{'4','3','9','2','5','1','6'},
{'4','6','2','9','8','5','3'},
{'4','6','8','3','2','5','9'},
{'4','7','2','9','5','8','6'},
{'4','7','2','9','8','5','3'},
{'4','7','5','6','2','8','9'},
{'4','7','8','3','5','2','6'},
{'4','8','2','9','6','7','5'},
{'4','8','6','5','2','7','9'},
{'4','8','9','2','5','1','6'},
{'4','9','3','8','5','7','6'},
{'4','9','5','6','3','7','8'},
{'4','9','5','6','8','2','3'},
{'4','9','8','3','5','2','6'},
{'4','9','8','3','6','1','5'},
{'6','1','2','7','4','9','5'},
{'6','1','2','7','5','8','4'},
{'6','1','5','4','2','8','7'},
{'6','1','5','4','7','3','2'},
{'6','1','7','2','5','3','4'},
{'6','2','1','8','5','9','4'},
{'6','2','4','5','8','3','1'},
{'6','2','8','1','4','3','5'},
{'6','3','2','7','5','8','4'},
{'6','3','5','4','8','2','1'},
{'6','3','8','1','2','5','7'},
{'6','3','8','1','5','2','4'},
{'6','4','2','7','8','5','1'},
{'6','4','8','1','2','5','7'},
{'6','7','1','8','5','9','4'},
{'6','7','5','4','1','9','8'},
{'6','7','5','4','8','2','1'},
{'6','7','8','1','4','3','5'},
{'6','7','8','1','5','2','4'},
{'6','8','2','7','4','9','5'},
{'6','8','4','5','2','9','7'},
{'6','8','7','2','5','3','4'},
{'6','9','2','7','5','8','4'},
{'6','9','2','7','8','5','1'},
{'6','9','5','4','2','8','7'},
{'6','9','8','1','5','2','4'},
{'8','1','3','4','5','7','2'},
{'8','1','4','3','2','9','5'},
{'8','1','4','3','5','6','2'},
{'8','1','5','2','3','7','4'},
{'8','1','5','2','4','6','3'},
{'8','2','4','3','6','5','1'},
{'8','2','6','1','4','5','3'},
{'8','3','1','6','5','9','2'},
{'8','3','5','2','1','9','6'},
{'8','3','5','2','6','4','1'},
{'8','3','6','1','2','7','5'},
{'8','3','6','1','5','4','2'},
{'8','4','1','6','5','9','2'},
{'8','4','2','5','6','7','1'},
{'8','4','6','1','2','7','5'},
{'8','6','2','5','4','9','3'},
{'8','6','3','4','5','7','2'},
{'8','6','4','3','2','9','5'},
{'8','7','4','3','5','6','2'},
{'8','7','5','2','6','4','1'},
{'8','7','6','1','4','5','3'},
{'8','7','6','1','5','4','2'},
{'8','9','4','3','5','6','2'},
{'8','9','4','3','6','5','1'},
{'8','9','5','2','4','6','3'},
{'8','9','6','1','5','4','2'}};



    static int first_index=0;
    static int last_index=103;
    int CPU_choose;
    int index,i;
    char value_in_index;
    int value;
    int flag=0;
    srand(time(0));

//------------------------------------------------------------------------------------------------------------------------------
    if(choice[1]=='5') // special case when USER enters 5 in 2nd turn
    {
        if(turn_n==3)
        {
            char   array4five[12]={'1','3','8','7','6','1','9','4','3','7','2','9'};
                    index=(int)choice[0]-48;
                    index=index/2;
                    index=index*3;
                    index=index-((rand()%3)+1);// got suitable index randomly
                    value_in_index=array4five[index];

        }

        else  // when turn is not 3
        {
            value_in_index=if_wins(turn_n,choice);
            if(value_in_index=='N')  // checking if CPU can win
            {
                value_in_index=if_wins(turn_n+1,choice);
                if(value_in_index=='N')  // to interrupt user from winning
                {
                          if(turn_n==5&&value_in_index=='N')
                            {
                                for(i='1';i<='9';i++)
                                {
                                   if(check(1,choice,i)&&check(3,choice,i))
                                    {
                                        flag=1;
                                        break;
                                    }
                                }
                            }
                        if(flag==1) // magic worked
                        {
                            value_in_index=i;
                        }
                        else
                        {
                            value_in_index=get_random(choice);// picking up random number if nothing works
                        }
                }
            }
         }

    choice[turn_n-1]=value_in_index;

    value=change_index_CPU(value_in_index);
    game[value-1]='X';

    value_in_index=(char)value+48;
    return value_in_index;//returning value in char
    }
//-----------------------------------------------------------------------------------------------------------

    // reconstruct first index  and last index  for next turn of CPU
    if(choice[0]!='0') // if not first time then it needs to change according to users's entry
    {
        for(i=first_index;i<=last_index;i++)
        {
                if(choice[turn_n-2]==CPU[i][turn_n-2])
                {
                    first_index=i;// first index changed
                    break;
                }
        }

        for(i=last_index;i>=first_index;i--)
        {
                if(choice[turn_n-2]==CPU[i][turn_n-2])
                {
                    last_index=i;// last index changed
                    break;
                }
        }
    }

    // if CPU can win right now
    value_in_index=if_wins(turn_n,choice);
    if(value_in_index=='N')
    {
        value_in_index=if_wins(turn_n+1,choice);// if user is winning then insert in that cell
        if(value_in_index=='N')
        {
                        // get random value between first_index and last_index
                index=(last_index-first_index)+1;
                index=rand()%index;
                index=first_index+index; // got index value randomly

                value_in_index=CPU[index][turn_n-1]; // getting value to compare to all the arrays of CPU

                for(i=first_index;i<=last_index;i++)// to find out new first index
                {
                    if(CPU[i][turn_n-1]==value_in_index)
                    {
                        first_index = i;
                        break;
                    }
                }
                for(i=last_index;i>=first_index;i--)// to find out new last index
                {
                    if(CPU[i][turn_n-1]==value_in_index)
                    {
                        last_index = i;
                        break;
                    }
                }
        }
    }
    choice[turn_n-1]=value_in_index;
    value=change_index_CPU(value_in_index);
    game[value-1]='X';
    value_in_index=(char)value+48;
    return value_in_index;//returning value in char

}

/// MEDIUM LEVEL----------------------------------------
char CPU_turn_medium(int turn_n,char game[], char choice[])//CPU's entry for hard level
{
    char value_in_char;
    int index,flag=0;
    char i;

    value_in_char=if_wins(turn_n,choice);
    if(value_in_char!='N')
    {
        flag=2;
    }
    else if(value_in_char=='N')
    {
        value_in_char=if_wins(turn_n+1,choice);
        if(value_in_char!='N')
        {
            flag=2;
        }
    }

    if(turn_n==5&&value_in_char=='N')
    {
        for(i='1';i<='9';i++)
        {
           if(check(1,choice,i)&&check(3,choice,i))
            {
                flag=1;
                break;
            }
        }

    }
    if(turn_n==7&&value_in_char=='N')
    {

        for(i='1';i<='9';i++)
        {
            if( (check(1,choice,i)&&check(3,choice,i)) || (check(3,choice,i)&&check(5,choice,i)) || (check(1,choice,i)&&check(5,choice,i)) )
            {
                flag=1;
                break;
            }
        }

    }

    if(flag==1)
    {
        value_in_char=i;
        index=change_index_CPU(value_in_char);
    }
    else if(flag==2)
    {
        index=change_index_CPU(value_in_char);
    }
    else{
        value_in_char=get_random(choice);
        index=change_index_CPU(value_in_char);
    }
    game[index-1]='X';

    choice[turn_n-1]=value_in_char;

    value_in_char=(char)index+48;
    return value_in_char;
}

/// EASY LEVEL------------------------------------------
char CPU_turn_easy(char game[])//CPU's entry for hard level
{

    srand(time(0));
    int index=rand()%9;

     while(game[index]!=' ')
     {
         index=rand()%9;
     }
    game[index]='X';
    return ((char)(index+1)+48);
}

/// MULTIPLAYER-----------------------------------------
void Multiplayer(int turn_n,char game[])
{
    char choice_converted;
    int choice=0;
    int flag=0;
    system("cls");
    board(game);
    printf("\n\nPlayer 1 [X]");
    printf("\nPlayer 2 [0]");

    printf("\n\n\t Player %d turn : ",2-(turn_n%2));
    scanf("%d",&choice);

    while(choice>9||choice<1)
    {
        printf("\n\tInvalid Entry try again : ");
        scanf(" %d",&choice);
    }

    do{
        if(game[choice-1]!=' ')
        {
            printf("\n\t Space already occupied! try again : ");
            scanf(" %d",&choice);
        }
        else{
            flag=1;
        }

    }
    while(flag==0);

    if(turn_n%2==0)
    {
        game[choice-1]='0';
    }
    else
    {
        game[choice-1]='X';
    }


    return ;
}

///-------------


void CPU_turn(int turn_n,char game[],char choice_history[],int level)
{
    char choice;

        system("cls");
        if(level==1)// hard
        {
            choice = CPU_turn_hard(turn_n,game,choice_history);
        }
        else if(level==2) // medium
        {
            choice = CPU_turn_medium(turn_n,game,choice_history);
        }
        else{
             choice = CPU_turn_easy(game);
        }
        board(game);
        printf("\n\n\n\t CPU entered : %c     ",choice);
        system("pause");
        return;
}


void USER_turn(int turn_n,char game[],char choice_history[])
{
    char choice_converted;
    char choice;

    system("cls");
    board(game);

    printf("\n\n\n\t Your turn : ");
    do{
        scanf(" %c",&choice);
        choice_converted = check_for_user_valid(game,choice);
    }while(choice_converted == 'N');// check till user does not enter the right value

    choice_history[turn_n-1]=choice_converted;
}


///------------

void display_turns(char game[],int CPUfirst,int level)/// Displaying turns
{
     char choice_history[9]={'0'};
    int turn_n=1;
    int game_over=0;
    char playAgain;

    int main(void);// declaring main function
// two player-------------
    if(level==4)
    {
        while(game_over==0)
        {
            Multiplayer(turn_n,game);
            game_over=gameover(game);
            turn_n++;
        }

    }
///////////---------------------

// CPU vs USER---------------------------
    else if(CPUfirst==1)// CPU enter first
    {
        while(game_over==0)
        {
            if(turn_n%2!=0)
            {
                CPU_turn(turn_n,game,choice_history,level);
            }
            else
            {
                USER_turn(turn_n,game,choice_history);
            }
            game_over=gameover(game);
            turn_n++;
        }

    }

    else // user enters first
    {
        while(game_over==0)
        {
            if(turn_n%2!=0)
            {
                  USER_turn(turn_n,game,choice_history);
            }
            else
            {
                  CPU_turn(turn_n,game,choice_history,level);
            }
            game_over=gameover(game);
            turn_n++;
        }
    }
// CPU vs USER  end---------------------------

    system("cls");
    board(game);

     if(game_over==2)// Game Draw
    {
         printf("\n\n\n\t -- GAME DRAW --\n\n");

    }
    else if(level==4)// if some one wins two users
    {
        printf("\n\n\n\t -- Congratulations!! Player %d wins!\n\n",turn_n%2+1);
    }
    else if(turn_n%2==0)// CPU wins // if turn is even  -because turn_n is being incremented at last
    {
        if(CPUfirst==1)
        {
                printf("\n\n\n\t --YOU LOSE --\n\n");
        }
        else // user wins  which is not possible in hard level
        {
                printf("\n\n\n\t -- Congratulations!!  YOU WIN --\n\n");
        }
    }
    else
    {
        if(CPUfirst==1)
        {
            printf("\n\n\n\t -- Congratulations!!  YOU WIN --\n\n");
        }
        else
        {
            printf("\n\n\n\t --YOU LOSE --\n\n");
        }
    }


    printf(" 1. Play again");
    printf("\n 2. Exit \n");
    printf("\n enter your choice : ");
    scanf(" %c",&playAgain);
    while(playAgain<'1'||playAgain>'2')
    {
        printf("invalid entry! try again : ");
        scanf(" %c",&playAgain);
    }

    if(playAgain=='1')
    {
        system("cls");
        main();
    }

    return;
}


int main()
{
    srand(time(0));

    char game[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int level;

    introduction();
    board(game);

    printf("\n\n\n\n  1. PRO\n");
    printf("  2. INTERMEDIATE\n");
    printf("  3. NOOB\n");
    printf("  4. PLAY WITH MY BUDDY");

    printf("\n\n enter your choice : ");
     scanf("%d",&level);

    while(level>4||level<1)
    {
        printf("\n\n invalid entry! enter again : ");
        scanf("%d",&level);
    }

    if(level==1) // in hard level CPU always enters first
    {
        display_turns(game,1,level);
    }
    else
    {
        display_turns(game,rand()%2,level);
    }

    return 0;
}

