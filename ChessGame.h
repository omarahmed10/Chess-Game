void PrintBoard();
void BuildBoard();
void DetectMove();
void GetMove();
void CheckMove_FirstPlayer();
void CheckMove_SecondPlayer();
void CheckPieces_FirstPlayer();
void CheckPieces_SecondPlayer();
int PawnMove_FirstPlayer(int n,int m,int x,int y);
int PawnMove_SecondPlayer(int n,int m,int x,int y);
int KingMove(int n,int m,int x,int y);
int RockMove(int n,int m,int x,int y);
int BishopMove(int n,int m,int x,int y);
int QueenMove(int n,int m,int x,int y);
int KnightMove(int n,int m,int x,int y);
void CheckPromotion_FirstPlayer(int p);
void CheckPromotion_SecondPlayer(int p);
void Check_FirstPlayer(int x,int y);
void checkmate_FirstPlayer(int g,int h);
void Check_SecondPlayer(int x,int y);
void checkmate_secondPlayer(int g,int h);
void Temp_Move(int n ,int m ,int x ,int y,int g,int h);
void Checking_StaleMate(int g,int h);

int i,j,x,y,m,n,k,CheckMate=0,StaleMate=1,noOfLinesFP=0,noOfLinesSP=0,u=0,v=0 ,noOfUndoFP=0,noOfUndoSP=0;
int a=1,b=1,found,flag,a1=0,a2=0,a3,a4,CheckingPiecesPlace[8][2],CheckingPieces,NoOfTurns=0;
char Board[10][14];
char Move[4],ch;
int A,B;
int promote=0,s=0,d=0,g=0,h=0,Promote1[8]={0},Promote2[8]={0};

void BuildBoard(){
    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            if((i+j)%2==0){
                Board[i][j]='-';
                }
            else Board[i][j]='.';
        }
    }
    i=1;j=1;
    while(j<9){
        Board[2][j]='p';
        Board[7][j]='P';
        Board[0][j]=64+j;       ///64 is '@' in ASCII code which is before 'A'
        Board[9][j]=64+j;
        ++j;
    }
    while(i<9){
        Board[i][0]=57-i;       ///57 is '9' in ASCII code
        Board[i][9]=57-i;
        ++i;
    }
Board[1][1]='r';Board[1][2]='n';Board[1][3]='b';Board[1][4]='q';Board[1][5]='k';Board[1][6]='b';Board[1][7]='n';Board[1][8]='r';
Board[8][1]='R';Board[8][2]='N';Board[8][3]='B';Board[8][4]='Q';Board[8][5]='K';Board[8][6]='B';Board[8][7]='N';Board[8][8]='R';
Board[9][9]=Board[0][0]=Board[0][9]=Board[9][0]=' ';
}

void PrintBoard(){
    system("cls");
    for(i=0;i<10;i++){
        for(j=0;j<14;j++){
            printf("\t%c",Board[i][j]);
        }
        printf("\n");
        if(i<9)
        printf("\t\t=========================================================");
        printf("\n");
    }
}

void GetMove(){
    for(i=0;i<4;i++){
        scanf(" %c",&Move[i]);
}
fflush(stdin);
}

void DetectMove(){
        switch(Move[0]){
            case 'A':{y=1; found=1; break;}
            case 'B':{y=2; found=1; break;}
            case 'C':{y=3; found=1; break;}
            case 'D':{y=4; found=1; break;}
            case 'E':{y=5; found=1; break;}
            case 'F':{y=6; found=1; break;}
            case 'G':{y=7; found=1; break;}
            case 'H':{y=8; found=1; break;}
            default:found=0;}
        switch(Move[1]){
            case '1':{x=9-1; found=1; break;}
            case '2':{x=9-2; found=1; break;}
            case '3':{x=9-3; found=1; break;}
            case '4':{x=9-4; found=1; break;}
            case '5':{x=9-5; found=1; break;}
            case '6':{x=9-6; found=1; break;}
            case '7':{x=9-7; found=1; break;}
            case '8':{x=9-8; found=1; break;}
            default:found=0;}


        switch(Move[2]){
            case 'A':{m=1;found=1; break;}
            case 'B':{m=2;found=1; break;}
            case 'C':{m=3;found=1; break;}
            case 'D':{m=4;found=1; break;}
            case 'E':{m=5;found=1; break;}
            case 'F':{m=6;found=1; break;}
            case 'G':{m=7;found=1; break;}
            case 'H':{m=8;found=1; break;}
            default:found=0;}
        switch(Move[3]){
            case '1':{n=9-1;found=1;break;}
            case '2':{n=9-2;found=1;break;}
            case '3':{n=9-3;found=1;break;}
            case '4':{n=9-4;found=1;break;}
            case '5':{n=9-5;found=1;break;}
            case '6':{n=9-6;found=1;break;}
            case '7':{n=9-7;found=1;break;}
            case '8':{n=9-8;found=1;break;}
            default:found=0;}


}

void CheckMove_FirstPlayer(){
    switch (Board[x][y]){
    case 'N': { KnightMove(n,m,x,y);
                break; }
    case 'Q': { QueenMove(n,m,x,y);
                break;}
    case 'B': { BishopMove(n,m,x,y);
                break; }
    case 'R': { RockMove(n,m,x,y);
                break; }
    case 'K': { KingMove(n,m,x,y);
                break; }

    case 'P': { PawnMove_FirstPlayer(n,m,x,y);
                break; }
    default:
            found=1;
    }

}

void CheckMove_SecondPlayer(){
    switch (Board[x][y]){
    case 'n': { KnightMove(n,m,x,y);
                break;}
    case 'q': { QueenMove(n,m,x,y);
                break; }
    case 'b': { BishopMove(n,m,x,y);
                break; }
    case 'r': { RockMove(n,m,x,y);
                break; }
    case 'k': { KingMove(n,m,x,y);
                break; }

    case 'p': { PawnMove_SecondPlayer(n,m,x,y);
                break; }
    default:
            found=1;
    }
}

                    //Player 1 Can't attack his pieces

void CheckPieces_FirstPlayer(){
    switch(Board[n][m]){
    case 'R':
    case 'N':
    case 'B':
    case 'Q':
    case 'K':
    case 'P':
        {
            flag=1;
            break;
        }
    default:
        flag=0;

    }
}

                    //Player 2 can't attack his pieces

void CheckPieces_SecondPlayer(){
    switch(Board[n][m]){
    case 'r':
    case 'n':
    case 'b':
    case 'q':
    case 'k':
    case 'p':
        {
            flag=1;
            break;
        }
    default:
        flag=0;
    }
}

                    //Checking Pawn Move for 1st Player

int PawnMove_FirstPlayer(int n,int m,int x,int y){
    if(Board[7][y]=='P' && (y==m&&x==n+2)){
            if(isalpha(Board[n][m]) || isalpha(Board[6][y]))
                found=1;
            else
                found=0;
            }
    else if((Board[x-1][y]=='-'||Board[x-1][y]=='.') && (y==m && x==n+1)){
            found=0;
        }

    else if(m==y+1&&n==x-1){
        switch(Board[n][m]){
        case 'p':
        case 'r':
        case 'n':
        case 'b':
        case 'q':
        case 'k':
            {
                found=0;
                break;
            }
        default:
                found=1;
        }
    }
    else if(m==y-1&&n==x-1){
        switch(Board[n][m]){
        case 'p':
        case 'r':
        case 'n':
        case 'b':
        case 'q':
        case 'k':
            {
                found=0;
                break;
            }
        default:
                found=1;
        }
    }
    else
        found=1;

    return found;
}

                    //Checking Pawn move for 2nd Player

int PawnMove_SecondPlayer(int n,int m,int x,int y){
    if(Board[2][y]=='p' && (m==y && x==n-2)){
            if(isalpha(Board[n][m]) || isalpha(Board[3][y]))
                found=1;
            else
                found=0;
    }
    else if((Board[x+1][y]=='-'||Board[x+1][y]=='.') && (m==y && x==n-1)){
            found=0;
            }
    else if(m==y+1&&n==x+1){
        switch(Board[n][m]){
        case 'P':
        case 'R':
        case 'N':
        case 'B':
        case 'Q':
        case 'K':
            {
                found=0;
                break;
            }
        default:
            {
                found=1;
            }
        }
    }
    else if(m==y-1&&n==x+1){
        switch(Board[n][m]){
        case 'P':
        case 'R':
        case 'N':
        case 'B':
        case 'Q':
        case 'K':
            {
                found=0;
                break;
            }
        default:
            {
                found=1;
            }
        }
    }
    else
        found=1;

    return found;
}

                    //Checking King Move

int KingMove(int n,int m,int x,int y){
    if((n==x&&m==y-1)||(n==x&&m==y+1)){
        if(isalpha(Board[n][m])){
            if( ( Board[x][y]=='K') && (islower(Board[n][m])) )found=0;
            else if( (Board[x][y]=='k') && (isupper(Board[n][m])) )found=0;
            else found=1;
        }
        else found=0;
    }
    else if ((n==x-1&&m==y)||(n==x+1&&m==y)){
        if(isalpha(Board[n][m])){
            if( ( Board[x][y]=='K') && (islower(Board[n][m])) )found=0;
            else if((Board[x][y]=='k') && (isupper(Board[n][m])) )found=0;
            else found=1;
        }
        else found=0;
    }
    else if ((n==x+1&&m==y+1)||(n==x+1&&m==y-1)||(n==x-1&&m==y+1)||(n==x-1&&m==y-1)){
        if(isalpha(Board[n][m])){
            if( ( Board[x][y]=='K') && (islower(Board[n][m])) )found=0;
            else if((Board[x][y]=='k') && (isupper(Board[n][m])) )found=0;
            else found=1;
        }
        else found=0;
    }
    else
        found=1;

    return found;
}

                    //Checking Rock Move

int RockMove(int n,int m,int x,int y)
{
    if( (isupper(Board[x][y]) && islower(Board[n][m])) || (islower(Board[x][y]) && isupper(Board[n][m])) || !isalpha(Board[n][m])){
         /////////////***** checking something in his way *****///////////////
        if((n==x&&m>y))
                {   found=0;
                    for(i=y+1;i<m;i++){
                        if(Board[n][i] !='-' && Board[n][i]!='.'){
                            found=1;
                            break; }
                            }
                }


        else if((n==x&&m<y))
                {   found=0;
                    for(i=m+1;i<y;i++){
                        if(Board[n][i]!='-' && Board[n][i]!='.'){
                            found=1;
                            break; }
                            }
                }

        else if((n>x&&m==y))
                {   found=0;
                    for(i=x+1;i<n;i++){
                        if(Board[i][m]!='-' && Board[i][m]!='.'){
                            found=1;
                            break; }
                            }
                }

        else if((n<x&&m==y))
                {   found=0;
                    for(i=n+1;i<x;i++){
                        if(Board[i][m]!='-' && Board[i][m]!='.'){
                            found=1;
                            break; }
                            }
                }
        else
            found=1;
        }
    else
        found=1;
    return found;
}
                    //Checking Bishop Move

int BishopMove(int n,int m,int x,int y)
{
    if( (isupper(Board[x][y]) && islower(Board[n][m])) || (islower(Board[x][y]) && isupper(Board[n][m])) || !isalpha(Board[n][m])){
        /////////////***** checking something in his way *****///////////////
        if(n>x&&m>y&&(n-x)==(m-y))
        {
            found=0;
            j=1;
            for(i=x+1;i<n;i++){
                if(Board[x+j][y+j]!='-' && Board[x+j][y+j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n<x&&m>y&&(x-n)==(m-y))
        {
            found=0;
            j=1;
            for(i=n+1;i<x;i++){
                if(Board[x-j][y+j]!='-' && Board[x-j][y+j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n>x&&m<y&&(n-x)==(y-m))
        {
            found=0;
            j=1;
            for(i=x+1;i<n;i++){
                if(Board[x+j][y-j]!='-' && Board[x+j][y-j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n<x&&m<y&&(x-n)==(y-m))
        {
            found=0;
            j=1;
            for(i=n+1;i<x;i++){
                if(Board[x-j][y-j]!='-' && Board[x-j][y-j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }
        else
            found=1;
    }
    else
        found=1;
    return found;
}

                    //Checking Queen Move = Bishop Move + Rock Move

int QueenMove(int n,int m,int x,int y)
{
    if( (isupper(Board[x][y]) && islower(Board[n][m])) || (islower(Board[x][y]) && isupper(Board[n][m])) || !isalpha(Board[n][m])){
        /////////////***** checking something in his way *****///////////////
        if((n==x&&m>y))
                {   found=0;
                    for(i=y+1;i<m;i++){
                        if(Board[n][i] !='-' && Board[n][i]!='.'){
                            found=1;
                            break; }
                            }
                }


        else if((n==x&&m<y))
                {   found=0;
                    for(i=m+1;i<y;i++){
                        if(Board[n][i]!='-' && Board[n][i]!='.'){
                            found=1;
                            break; }
                            }
                }

        else if((n>x&&m==y))
                {   found=0;
                    for(i=x+1;i<n;i++){
                        if(Board[i][m]!='-' && Board[i][m]!='.'){
                            found=1;
                            break; }
                            }
                }

        else if((n<x&&m==y))
                {   found=0;
                    for(i=n+1;i<x;i++){
                        if(Board[i][m]!='-' && Board[i][m]!='.'){
                            found=1;
                            break; }
                            }
                }

        else if(n>x&&m>y&&(n-x)==(m-y))
        {
            found=0;
            j=1;
            for(i=x+1;i<n;i++){
                if(Board[x+j][y+j]!='-' && Board[x+j][y+j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n<x&&m>y&&(x-n)==(m-y))
        {
            found=0;
            j=1;
            for(i=n+1;i<x;i++){
                if(Board[x-j][y+j]!='-' && Board[x-j][y+j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n>x&&m<y&&(n-x)==(y-m))
        {
            found=0;
            j=1;
            for(i=x+1;i<n;i++){
                if(Board[x+j][y-j]!='-' && Board[x+j][y-j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }

        else if(n<x&&m<y&&(x-n)==(y-m))
        {
            found=0;
            j=1;
            for(i=n+1;i<x;i++){
                if(Board[x-j][y-j]!='-' && Board[x-j][y-j]!='.'){
                    found=1;
                    break;
                }
                j++;
            }
        }
        else
            found=1;
    }
    else
        found=1;
    return found;
}
                    //Checking Knight Move

int KnightMove(int n,int m,int x,int y)
{
    if( (isupper(Board[x][y]) && islower(Board[n][m])) || (islower(Board[x][y]) && isupper(Board[n][m])) || !isalpha(Board[n][m])){
        /////////////***** checking something in his way *****///////////////
        if (n==x+2&&m==y+1)
            found=0;
        else if (n==x+2&&m==y-1)
            found=0;
        else if (n==x+1&&m==y+2)
            found=0;
        else if (n==x+1&&m==y-2)
            found=0;
        else if (n==x-1&&m==y+2)
            found=0;
        else if (n==x-1&&m==y-2)
            found=0;
        else if (n==x-2&&m==y+1)
            found=0;
        else if (n==x-2&&m==y-1)
            found=0;
        else
            found=1;
    }
    else
        found=1;
    return found;
}
                    //Checking Promotion For First Player

void CheckPromotion_FirstPlayer(int p)
{
    s=p;
    printf("For Promotion (to a queen Enter Q) , (to a Rock Enter R)\n");
    printf("For Promotion (to a Bishop Enter B) , (to a Knight Enter N)\n");
    printf("Promotion to : ");
    fflush(stdin);

    Promote1[g]=s;
    g++;
    k=1;
    while(k==1){
            scanf(" %c",&ch);
    switch(ch){
                        //Queening
    case 'Q': { Board[1][s]='Q';
                PrintBoard();
                k=0;
                break; }
                        //Under Promoting
    case 'R': { Board[1][s]='R';
                PrintBoard();
                k=0;
                break; }

    case 'B': { Board[1][s]='B';
                PrintBoard();
                k=0;
                break; }

    case 'N': { Board[1][s]='N';
                PrintBoard();
                k=0;
                break; }

    default:  printf("Invalid\n");


    }
    promote++;
    }
}

                 //Checking Promotion For Second Player

void CheckPromotion_SecondPlayer(int p)
{
    d=p;
    printf("For Promotion (to a queen Enter q) , (to a Rock Enter r)\n");
    printf("For Promotion (to a Bishop Enter b) , (to a Knight Enter n)\n");
    printf("Promotion to : ");
    fflush(stdin);

    Promote2[h]=d;
    h++;
    k=1;
    while(k==1){
            scanf(" %c",&ch);
    switch(ch){
                        //Queening
    case 'q': { Board[8][d]='q';
                PrintBoard();
                k=0;
                break; }
                        //Under Promoting
    case 'r': { Board[8][d]='r';
                PrintBoard();
                k=0;
                break; }

    case 'b': { Board[8][d]='b';
                PrintBoard();
                k=0;
                break; }

    case 'n': { Board[8][d]='n';
                PrintBoard();
                k=0;
                break; }

    default:  printf("Invalid\n");

        }
    promote++;
    }
}

/******
*******
    ******************************************* CHECK MATE *******************************************
*******
*******/
void Check_FirstPlayer(int x,int y){
    int i=0,j=0;      //////////////they are counters not king place
    CheckingPieces=0;
    if(Board[x-1][y-1]=='p'  && (x-1)>=1 && (y-1)>=1 ){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;
    }
    else if(Board[x-1][y+1]=='p' && (y+1)<9 && (x-1)>=1 ){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;
    }
    for(j=y+1;j<9;j++){
        if(Board[x][j] =='r' || Board[x][j]=='q'){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x;CheckingPiecesPlace[CheckingPieces-1][1]=j;
        break; }
        else if(isalpha(Board[x][j])) break;         ///////if found any other character it should stop searching
    }
    for(j=y-1;j>0;j--){
        if(Board[x][j] =='r' || Board[x][j]=='q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x;CheckingPiecesPlace[CheckingPieces-1][1]=j;
            break; }
        else if(isalpha(Board[x][j])) break;
    }
    for(i=x+1;i<9;i++){
        if(Board[i][y]=='r' || Board[i][y]=='q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=i;CheckingPiecesPlace[CheckingPieces-1][1]=y;
            break; }
        else if(isalpha(Board[i][y])) break;
    }
    for(i=x-1;i>0;i--){
        if(Board[i][y]=='r' || Board[i][y]=='q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=i;CheckingPiecesPlace[CheckingPieces-1][1]=y;
            break; }
        else if(isalpha(Board[i][y])) break;
    }
    j=1;
    for(i=x+1;i<9;i++){                               ////////checking forth quad
        if((Board[x+j][y+j]=='b' || Board[x+j][y+j]=='q') && (x+j)<9 && (y+j)<9 ){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x+j;CheckingPiecesPlace[CheckingPieces-1][1]=y+j;
            break;}
        else if(isalpha(Board[x+j][y+j])) break;
        j++;
        }
    j=1;
    for(i=x+1;i<9;i++){                               ////////checking third quad
        if((Board[x+j][y-j]=='b' || Board[x+j][y-j]=='q') && (x+j)<9 && (y-j)>=1){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x+j;CheckingPiecesPlace[CheckingPieces-1][1]=y-j;
            break;}
        else if(isalpha(Board[x+j][y-j])) break;
        j++;
        }
    j=1;
    for(i=x-1;i>0;i--){                                 ////////checking first quad
        if((Board[x-j][y+j]=='b' || Board[x-j][y+j]=='q') && (x-j)>=1 && (y+j)<9 ){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x-j;CheckingPiecesPlace[CheckingPieces-1][1]=y+j;
            break;}
        else if(isalpha(Board[x-j][y+j])) break;
        j++;
        }
    j=1;
    for(i=x-1;i>0;i--){                                 ////////checking second quad
        if((Board[x-j][y-j]=='b' || Board[x-j][y-j]=='q') && (x-j)>=1 && (y-j)>=1 ){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x-j;CheckingPiecesPlace[CheckingPieces-1][1]=y-j;
            break;}
        else if(isalpha(Board[x-j][y-j])) break;
        j++;
        }
    if (Board[x+2][y+1]=='n' && (x+2)<9 && (y+1)<9 ){       //////checking knight attack use if not else if because in case of two knight attack
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+2;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;}
    if (Board[x+2][y-1]=='n' && (x+2)<9 && (y-1)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+2;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;}
    if (Board[x+1][y+2]=='n' && (x+1)<9 && (y+2)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+1;CheckingPiecesPlace[CheckingPieces-1][1]=y+2;}
    if (Board[x+1][y-2]=='n' && (x+1)<9 && (y-2)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+1;CheckingPiecesPlace[CheckingPieces-1][1]=y-2;}
    if (Board[x-1][y+2]=='n' && (x-1)>=1 && (y+2)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y+2;}
    if (Board[x-1][y-2]=='n' && (x-1)>=1 && (y-2)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y-2;}
    if (Board[x-2][y+1]=='n' && (x-2)>=1 && (y+1)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-2;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;}
    if (Board[x-2][y-1]=='n' && (x-2)>=1 && (y-1)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-2;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;}

    if(CheckingPieces>0){CheckMate=1;}
    else {CheckMate=0;}
}

void checkmate_FirstPlayer(int g,int h){    ////g,h are the king place
/**
**  First Check whether any piece can eat this checking piece
**/
    int l,r,cp=CheckingPieces,a;       ///////////any two different counter
    for(l=1;l<9;l++){               /////////looking for all pieces of player one
        for(r=1;r<9;r++){          //////////which can attack the checking piece
            switch(Board[l][r]){
            case 'P':
                {
                    if( CheckingPiecesPlace[cp-1][0]==l-1 && CheckingPiecesPlace[cp-1][1] == r+1 ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                    else if( CheckingPiecesPlace[cp-1][0]==l-1 && CheckingPiecesPlace[cp-1][1] == r-1 ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'R':
                {
                    if( !RockMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'B':
                {
                    if ( !BishopMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'N':
                {
                    if( !KnightMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'Q':
                {
                    if( !QueenMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_FirstPlayer(g,h); /////// because in case this move causes a check on the king
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'K':
                {
                    if( !KingMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_FirstPlayer(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1]);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            }
            if(cp==0)break;
        }
        if(cp==0)break;
    }
    if(cp==0){
            CheckMate=0;printf("Check\a\n");}
    else CheckMate=1;
/**
********* in every case i check first if the move will be valid
********* then i temporary moves this move and check whether the king
********* is in check or not and then return this move ....thats all
**/
if(CheckMate==1){
    for(l=1;l<9;l++){                    /////////looking for all pieces of player again
        for(r=1;r<9;r++){
            switch(Board[l][r]){
            case 'K':           /////////in case of moving the king don't send
                {              //////////The old place of the king (g,h)
                    if( !KingMove(l+1,r,l,r) && l+1<9 ){
                        Temp_Move(l+1,r,l,r,l+1,r);
                    }
                    if(CheckMate==0)break;              /// breaking from the switch
                    if( !KingMove(l+1,r+1,l,r) && l+1<9 && r+1<9){
                        Temp_Move(l+1,r+1,l,r,l+1,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l+1,r-1,l,r) && l+1<9 && r-1>=1){
                        Temp_Move(l+1,r-1,l,r,l+1,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l,r-1,l,r) && r-1>=1){
                        Temp_Move(l,r-1,l,r,l,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l,r+1,l,r) && r+1<9){
                        Temp_Move(l,r+1,l,r,l,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r+1,l,r) && r+1<9 && l-1>=1){
                        Temp_Move(l-1,r+1,l,r,l-1,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r-1,l,r) && l-1>=1 && r-1>=1){
                        Temp_Move(l-1,r-1,l,r,l-1,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,l-1,r);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'P':
                {
                    if( !PawnMove_FirstPlayer(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !PawnMove_FirstPlayer(l-2,r,l,r) && l-2>=1){
                        Temp_Move(l-2,r,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'R':
                {
                    for(a=1;a<(9-r);a++){
                        if( !RockMove(l,r+a,l,r) && r+a<9){
                            Temp_Move(l,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !RockMove(l+a,r,l,r) && l+a<9){
                            Temp_Move(l+a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !RockMove(l,r-a,l,r) && r-a>=1){
                            Temp_Move(l,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !RockMove(l-a,r,l,r) && l-a>=1){
                            Temp_Move(l-a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'N':
                {
                    if( !KnightMove(l-2,r+1,l,r) && l-2>=1 && r+1<9){
                        Temp_Move(l-2,r+1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-2,r-1,l,r) && l-2>=1 && r-1>=1){
                        Temp_Move(l-2,r-1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-1,r-2,l,r) && l-1>=1 && r-2>=1){
                        Temp_Move(l-1,r-2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-1,r+2,l,r) && l-1>=1 && r+2<9){
                        Temp_Move(l-1,r+2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+1,r-2,l,r) && l+1<9 && r-2>=1){
                        Temp_Move(l+1,r-2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+1,r+2,l,r) && l+1<9 && r+2<9){
                        Temp_Move(l+1,r+2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+2,r-1,l,r) && l+2<9 && r-1>=1){
                        Temp_Move(l+2,r-1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+2,r+1,l,r) && l+2<9 && r+1<9){
                        Temp_Move(l+2,r+1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'B':
                {
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                            Temp_Move(l-a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                            Temp_Move(l-a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                            Temp_Move(l+a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                            Temp_Move(l+a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'Q':
                {
                    for(a=1;a<(9-r);a++){
                        if( !QueenMove(l,r+a,l,r) && (r+a)<9){
                            Temp_Move(l,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !QueenMove(l+a,r,l,r) && (l+a)<9){
                            Temp_Move(l+a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !QueenMove(l,r-a,l,r) && (r-a)>=1){
                            Temp_Move(l,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !QueenMove(l-a,r,l,r) && (l-a)>=1){
                            Temp_Move(l-a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                            Temp_Move(l-a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                            Temp_Move(l-a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                            Temp_Move(l+a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                            Temp_Move(l+a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                        }
                    break;
                }
            if(CheckMate==0)break;
            }
        if(CheckMate==0)break;
        }
    if(CheckMate==0)break;
    }
if(CheckMate==0)
    printf("Check\a\n");
  }
}

void Check_SecondPlayer(int x,int y){
    int i=0,j=0;      //////////////they are counters not king place
    CheckingPieces=0;
    if( Board[x+1][y-1]=='P' && (x+1)<9 && (y-1)>=1 ){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;
    }
    else if(Board[x+1][y+1]=='P' && (y+1)<9 && (x+1)<9 ){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;
    }
    for(j=y+1;j<9;j++){
        if(Board[x][j] =='R' || Board[x][j]=='Q'){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x;CheckingPiecesPlace[CheckingPieces-1][1]=j;
        break; }
        else if(isalpha(Board[x][j])) break;         ///////if found any other character it should stop searching
    }
    for(j=y-1;j>0;j--){
        if(Board[x][j] =='R' || Board[x][j]=='Q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x;CheckingPiecesPlace[CheckingPieces-1][1]=j;
            break; }
        else if(isalpha(Board[x][j])) break;
    }
    for(i=x+1;i<9;i++){
        if(Board[i][y]=='R' || Board[i][y]=='Q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=i;CheckingPiecesPlace[CheckingPieces-1][1]=y;
            break; }
        else if(isalpha(Board[i][y])) break;
    }
    for(i=x-1;i>0;i--){
        if(Board[i][y]=='R' || Board[i][y]=='Q'){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=i;CheckingPiecesPlace[CheckingPieces-1][1]=y;
            break; }
        else if(isalpha(Board[i][y])) break;
    }
    j=1;
    for(i=x+1;i<9;i++){                               ////////checking forth quad
        if((Board[x+j][y+j]=='B' || Board[x+j][y+j]=='Q') && (x+j)<9 && (y+j)<9){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x+j;CheckingPiecesPlace[CheckingPieces-1][1]=y+j;
            break;}
        else if(isalpha(Board[x+j][y+j])) break;
        j++;
        }
    j=1;
    for(i=x+1;i<9;i++){                               ////////checking third quad
        if((Board[x+j][y-j]=='B' || Board[x+j][y-j]=='Q') && (x+j)<9 && (y-j)>=1){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x+j;CheckingPiecesPlace[CheckingPieces-1][1]=y-j;
            break;}
        else if(isalpha(Board[x+j][y-j])) break;
        j++;
        }
    j=1;
    for(i=x-1;i>0;i--){                                 ////////checking first quad
        if((Board[x-j][y+j]=='B' || Board[x-j][y+j]=='Q') && (x-j)>=1 && (y+j)<9){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x-j;CheckingPiecesPlace[CheckingPieces-1][1]=y+j;
            break;}
        else if(isalpha(Board[x-j][y+j])) break;
        j++;
        }
    j=1;
    for(i=x-1;i>0;i--){                                 ////////checking second quad
        if((Board[x-j][y-j]=='B' || Board[x-j][y-j]=='Q') && (x-j)>1 && (y-j)>=1){
            CheckingPieces++;
            CheckingPiecesPlace[CheckingPieces-1][0]=x-j;CheckingPiecesPlace[CheckingPieces-1][1]=y-j;
            break;}
        else if(isalpha(Board[x-j][y-j])) break;
        j++;
        }
    if (Board[x+2][y+1]=='N' && (x+2)<9 && (y+1)<9 ){   //////checking knight attack use if not else if because in case of two knight attack
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+2;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;}
    if (Board[x+2][y-1]=='N' && (x+2)<9 && (y-1)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+2;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;}
    if (Board[x+1][y+2]=='N' && (x+1)<9 && (y+2)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+1;CheckingPiecesPlace[CheckingPieces-1][1]=y+2;}
    if (Board[x+1][y-2]=='N' && (x+1)<9 && (y-2)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x+1;CheckingPiecesPlace[CheckingPieces-1][1]=y-2;}
    if (Board[x-1][y+2]=='N' && (x-1)>=1 && (y+2)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y+2;}
    if (Board[x-1][y-2]=='N' && (x-1)>=1 && (y-2)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-1;CheckingPiecesPlace[CheckingPieces-1][1]=y-2;}
    if (Board[x-2][y+1]=='N' && (x-2)>=1 && (y+1)<9){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-2;CheckingPiecesPlace[CheckingPieces-1][1]=y+1;}
    if (Board[x-2][y-1]=='N' && (x-2)>=1 && (y-1)>=1){
        CheckingPieces++;
        CheckingPiecesPlace[CheckingPieces-1][0]=x-2;CheckingPiecesPlace[CheckingPieces-1][1]=y-1;}
    if(CheckingPieces>0){CheckMate=1;}
    else CheckMate=0;
}

void checkmate_secondPlayer(int g,int h){    ////g,h are the king place
/**
**  First Check whether any piece can eat this checking piece
**/
    int l,r,cp=CheckingPieces,a;       ///////////any two different counter
   for(l=1;l<9;l++){               /////////looking for all pieces of player Two
        for(r=1;r<9;r++){          //////////which can attack the checking piece
            switch(Board[l][r]){
            case 'p':
                {
                    if( CheckingPiecesPlace[cp-1][0]==l+1 && CheckingPiecesPlace[cp-1][1] == r+1 ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                    else if( CheckingPiecesPlace[cp-1][0]==l+1 && CheckingPiecesPlace[cp-1][1] == r-1 ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'r':
                {
                    if( !RockMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'b':
                {
                    if ( !BishopMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'n':
                {
                    if( !KnightMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'q':
                {
                    if( !QueenMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_SecondPlayer(g,h);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
            case 'k':
                {
                    if( !KingMove(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1],l,r) ){
                        Check_SecondPlayer(CheckingPiecesPlace[cp-1][0],CheckingPiecesPlace[cp-1][1]);
                        if(CheckingPieces==0){
                        cp--;
                        break;}
                    }
                break;
                }
                if(cp==0)break;
            }
            if(cp==0)break;
        }
        if(cp==0)break;
    }
    if(cp==0){
        CheckMate=0;printf("Check\a\n");}
    else CheckMate=1;
/**
********* in every case i check first if the move will be valid
********* then i temporary moves this move and check whether the king
********* is in check or not and then return this move ....thats all
**/

if(CheckMate==1){
    for(l=1;l<9;l++){                    /////////looking for all pieces of player again
        for(r=1;r<9;r++){
            switch(Board[l][r]){
            case 'k':           /////////in case of moving the king don't send
                {              //////////The old place of the king (g,h)
                    if( !KingMove(l+1,r,l,r) && l+1<9 ){
                        Temp_Move(l+1,r,l,r,l+1,r);
                    }
                    if(CheckMate==0)break;              /// breaking from the switch
                    if( !KingMove(l+1,r+1,l,r) && l+1<9 && r+1<9){
                        Temp_Move(l+1,r+1,l,r,l+1,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l+1,r-1,l,r) && l+1<9 && r-1>=1){
                        Temp_Move(l+1,r-1,l,r,l+1,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l,r-1,l,r) && r-1>=1){
                        Temp_Move(l,r-1,l,r,l,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l,r+1,l,r) && r+1<9){
                        Temp_Move(l,r+1,l,r,l,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r+1,l,r) && r+1<9 && l-1>=1){
                        Temp_Move(l-1,r+1,l,r,l-1,r+1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r-1,l,r) && l-1>=1 && r-1>=1){
                        Temp_Move(l-1,r-1,l,r,l-1,r-1);
                    }
                    if(CheckMate==0)break;
                    if( !KingMove(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,l-1,r);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'p':
                {
                    if( !PawnMove_SecondPlayer(l+1,r,l,r) && l+1<9){
                        Temp_Move(l+1,r,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !PawnMove_SecondPlayer(l+2,r,l,r) && l+2<9){
                        Temp_Move(l+2,r,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'r':
                {
                    for(a=1;a<(9-r);a++){
                        if( !RockMove(l,r+a,l,r) && r+a<9){
                            Temp_Move(l,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !RockMove(l+a,r,l,r) && l+a<9){
                            Temp_Move(l+a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !RockMove(l,r-a,l,r) && r-a>=1){
                            Temp_Move(l,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !RockMove(l-a,r,l,r) && l-a>=1){
                            Temp_Move(l-a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'n':
                {
                    if( !KnightMove(l-2,r+1,l,r) && l-2>=1 && r+1<9){
                        Temp_Move(l-2,r+1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-2,r-1,l,r) && l-2>=1 && r-1>1){
                        Temp_Move(l-2,r-1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-1,r-2,l,r) && l-1>=1 && r-2>1){
                        Temp_Move(l-1,r-2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l-1,r+2,l,r) && l-1>=1 && r+2<9){
                        Temp_Move(l-1,r+2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+1,r-2,l,r) && l+1<9 && r-2>=1){
                        Temp_Move(l+1,r-2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+1,r+2,l,r) && l+1<9 && r+2<9){
                        Temp_Move(l+1,r+2,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+2,r-1,l,r) && l+2<9 && r-1>=1){
                        Temp_Move(l+2,r-1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                    if( !KnightMove(l+2,r+1,l,r) && l+2<9 && r+1<9){
                        Temp_Move(l+2,r+1,l,r,g,h);
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'b':
                {
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                            Temp_Move(l-a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                            Temp_Move(l-a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                            Temp_Move(l+a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                            Temp_Move(l+a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                break;
                }
            case 'q':
                {
                    for(a=1;a<(9-r);a++){
                        if( !QueenMove(l,r+a,l,r) && (r+a)<9){
                            Temp_Move(l,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !QueenMove(l+a,r,l,r) && (l+a)<9){
                            Temp_Move(l+a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !QueenMove(l,r-a,l,r) && (r-a)>=1){
                            Temp_Move(l,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !QueenMove(l-a,r,l,r) && (l-a)>=1){
                            Temp_Move(l-a,r,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                            Temp_Move(l-a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                            Temp_Move(l-a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                            Temp_Move(l+a,r+a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                    }
                    if(CheckMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                            Temp_Move(l+a,r-a,l,r,g,h);
                        }
                        if(CheckMate==0)break;
                        }
                    break;
                    }
            if(CheckMate==0 )break;
            }
        if(CheckMate==0 )break;
        }
    if(CheckMate==0 )break;
    }
if(CheckMate==0)
    printf("Check\a\n");
}

}

void Temp_Move(int n ,int m ,int x ,int y,int g,int h){
    char temp1;          ///////////this is a temporary swapping
    temp1=Board[n][m];
    Board[n][m]=Board[x][y];
    if(isupper(Board[x][y])){
        if((x+y)%2==0)Board[x][y]='-';
        else Board[x][y]='.';
        Check_FirstPlayer(g,h);
    }
    else if(islower(Board[x][y])){
        if((x+y)%2==0)Board[x][y]='-';
        else Board[x][y]='.';
        Check_SecondPlayer(g,h);
    }
    if(CheckingPieces==0){
        CheckMate=0;
        Board[x][y]=Board[n][m];       /////////returning the move
        Board[n][m]=temp1;
        }
    else {                            /////////returning the move
        CheckMate=1;
        Board[x][y]=Board[n][m];
        Board[n][m]=temp1;
        }
}


void Checking_StaleMate(int g,int h){
    StaleMate=1;
    int l,r;
    for(l=1;l<9;l++){                    /////////looking for all pieces of player again
        for(r=1;r<9;r++){
        if(islower(Board[l][r]) && NoOfTurns%2 != 0){       ///////checking stalemate for player 2
            switch(Board[l][r]){
            case 'k':           /////////in case of moving the king don't send
                {              //////////The old place of the king (g,h)
                    if( !KingMove(l+1,r,l,r) && l+1<9 ){
                        Temp_Move(l+1,r,l,r,l+1,r);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;         /// breaking from the switch and prevent checking other conditions
                    if( !KingMove(l+1,r+1,l,r) && l+1<9 && r+1<9){
                        Temp_Move(l+1,r+1,l,r,l+1,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l+1,r-1,l,r) && l+1<9 && r-1>=1){
                        Temp_Move(l+1,r-1,l,r,l+1,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l,r-1,l,r) && r-1>=1){
                        Temp_Move(l,r-1,l,r,l,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l,r+1,l,r) && r+1<9){
                        Temp_Move(l,r+1,l,r,l,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r+1,l,r) && r+1<9 && l-1>=1){
                        Temp_Move(l-1,r+1,l,r,l-1,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r-1,l,r) && l-1>=1 && r-1>=1){
                        Temp_Move(l-1,r-1,l,r,l-1,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,l-1,r);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                break;
                }
            case 'p':
                {
                    if( !PawnMove_SecondPlayer(l+1,r,l,r) && l+1<9){
                        Temp_Move(l+1,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !PawnMove_SecondPlayer(l+2,r,l,r) && l+2<9){
                        Temp_Move(l+2,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if( !PawnMove_SecondPlayer(l+1,r+1,l,r) && l+1<9 && r+1<9){
                        Temp_Move(l+1,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if( !PawnMove_SecondPlayer(l+1,r-1,l,r) && l+1<9 && r-1>=1){
                        Temp_Move(l+1,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                break;
                }
            case 'r':
                {
                    for(a=1;a<(9-r);a++){
                        if( !RockMove(l,r+a,l,r) && r+a<9){
                        Temp_Move(l,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !RockMove(l+a,r,l,r) && l+a<9){
                        Temp_Move(l+a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !RockMove(l,r-a,l,r) && r-a>=1){
                        Temp_Move(l,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !RockMove(l-a,r,l,r) && l-a>=1){
                        Temp_Move(l-a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                break;
                }
            case 'n':
                {
                    if( !KnightMove(l-2,r+1,l,r) && l-2>=1 && r+1<9){
                        Temp_Move(l-2,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-2,r-1,l,r) && l-2>=1 && r-1>=1){
                        Temp_Move(l-2,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-1,r-2,l,r) && l-1>=1 && r-2>=1){
                        Temp_Move(l-1,r-2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-1,r+2,l,r) && l-1>=1 && r+2<9){
                        Temp_Move(l-1,r+2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+1,r-2,l,r) && l+1<9 && r-2>=1){
                        Temp_Move(l+1,r-2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+1,r+2,l,r) && l+1<9 && r+2<9){
                        Temp_Move(l+1,r+2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+2,r-1,l,r) && l+2<9 && r-1>=1){
                        Temp_Move(l+2,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+2,r+1,l,r) && l+2<9 && r+1<9){
                        Temp_Move(l+2,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                break;
                }
            case 'b':
                {
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                        Temp_Move(l-a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                        Temp_Move(l-a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                        Temp_Move(l+a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                        Temp_Move(l+a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                break;
                }
            case 'q':
                {
                    for(a=1;a<(9-r);a++){
                        if( !QueenMove(l,r+a,l,r) && (r+a)<9){
                        Temp_Move(l,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !QueenMove(l+a,r,l,r) && (l+a)<9){
                        Temp_Move(l+a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !QueenMove(l,r-a,l,r) && (r-a)>=1){
                        Temp_Move(l,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !QueenMove(l-a,r,l,r) && (l-a)>=1){
                        Temp_Move(l-a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                        Temp_Move(l-a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                        Temp_Move(l-a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                        Temp_Move(l+a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                        Temp_Move(l+a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                break;
                }
            if(StaleMate==0)break;
            }
        if(StaleMate==0)break;
        }
        if(isupper(Board[l][r]) && NoOfTurns%2 == 0){      ///////checking stalemate for player 1
            switch(Board[l][r]){
            case 'K':           /////////in case of moving the king don't send
                {              //////////The old place of the king (g,h)
                    if( !KingMove(l+1,r,l,r) && l+1<9 ){
                        Temp_Move(l+1,r,l,r,l+1,r);
                        if(CheckingPieces==0)StaleMate=0;       //////thats mean before setting stalemate=0
                    }                                          //////check that the king will not be in a check
                    if(StaleMate==0)break;              /// breaking from the switch
                    if( !KingMove(l+1,r+1,l,r) && l+1<9 && r+1<9){
                        Temp_Move(l+1,r+1,l,r,l+1,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l+1,r-1,l,r) && l+1<9 && r-1>=1){
                        Temp_Move(l+1,r-1,l,r,l+1,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l,r-1,l,r) && r-1>=1){
                        Temp_Move(l,r-1,l,r,l,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l,r+1,l,r) && r+1<9){
                        Temp_Move(l,r+1,l,r,l,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r+1,l,r) && r+1<9 && l-1>=1){
                        Temp_Move(l-1,r+1,l,r,l-1,r+1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r-1,l,r) && l-1>=1 && r-1>=1){
                        Temp_Move(l-1,r-1,l,r,l-1,r-1);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !KingMove(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,l-1,r);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                break;
                }
            case 'P':
                {
                    if( !PawnMove_FirstPlayer(l-1,r,l,r) && l-1>=1){
                        Temp_Move(l-1,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !PawnMove_FirstPlayer(l-2,r,l,r) && l-2>=1){
                        Temp_Move(l-2,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !PawnMove_FirstPlayer(l-1,r-1,l,r) && l-1>=1 && r-1>=1){
                        Temp_Move(l-1,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                    if(StaleMate==0)break;
                    if( !PawnMove_FirstPlayer(l-1,r+1,l,r) && l-1>=1 && r+1<9){
                        Temp_Move(l-1,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                    }
                break;
                }
            case 'R':
                {
                    for(a=1;a<(9-r);a++){
                        if( !RockMove(l,r+a,l,r) && r+a<9){
                        Temp_Move(l,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !RockMove(l+a,r,l,r) && l+a<9){
                        Temp_Move(l+a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                        }
                    if(StaleMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !RockMove(l,r-a,l,r) && r-a>=1){
                        Temp_Move(l,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                        }
                    if(StaleMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !RockMove(l-a,r,l,r) && l-a>=1){
                        Temp_Move(l-a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                        }
                        if(StaleMate==0)break;
                    }
                break;
            case 'N':
                {
                    if( !KnightMove(l-2,r+1,l,r) && l-2>=1 && r+1<9){
                        Temp_Move(l-2,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-2,r-1,l,r) && l-2>=1 && r-1>=1){
                        Temp_Move(l-2,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-1,r-2,l,r) && l-1>=1 && r-2>=1){
                        Temp_Move(l-1,r-2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l-1,r+2,l,r) && l-1>=1 && r+2<9){
                        Temp_Move(l-1,r+2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+1,r-2,l,r) && l+1<9 && r-2>=1){
                        Temp_Move(l+1,r-2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+1,r+2,l,r) && l+1<9 && r+2<9){
                        Temp_Move(l+1,r+2,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+2,r-1,l,r) && l+2<9 && r-1>=1){
                        Temp_Move(l+2,r-1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                    if(StaleMate==0)break;
                    if( !KnightMove(l+2,r+1,l,r) && l+2<9 && r+1<9){
                        Temp_Move(l+2,r+1,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                            }
                break;
                }
            case 'B':
                {
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                        Temp_Move(l-a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !BishopMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                        Temp_Move(l-a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                        Temp_Move(l+a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !BishopMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                        Temp_Move(l+a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                break;
                }
            case 'Q':
                {
                    for(a=1;a<(9-r);a++){
                        if( !QueenMove(l,r+a,l,r) && (r+a)<9){
                        Temp_Move(l,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(9-l);a++){
                        if( !QueenMove(l+a,r,l,r) && (l+a)<9){
                        Temp_Move(l+a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(r-1);a++){
                        if( !QueenMove(l,r-a,l,r) && (r-a)>=1){
                        Temp_Move(l,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<(l-1);a++){
                        if( !QueenMove(l-a,r,l,r) && (l-a)>=1){
                        Temp_Move(l-a,r,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r+a,l,r) && (l-a)>=1 && (r+a)<9){
                        Temp_Move(l-a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<l-1 || a<r-1;a++){
                        if( !QueenMove(l-a,r-a,l,r) && (l-a)>=1 && (r-a)>=1){
                        Temp_Move(l-a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r+a,l,r) && (l+a)<9 && (r+a)<9){
                        Temp_Move(l+a,r+a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                    if(StaleMate==0)break;
                    for(a=1;a<9-l || a<9-r;a++){
                        if( !QueenMove(l+a,r-a,l,r) && (l+a)<9 && (r-a)>=1){
                        Temp_Move(l+a,r-a,l,r,g,h);
                        if(CheckingPieces==0)StaleMate=0;
                        }
                        if(StaleMate==0)break;
                    }
                break;
                }
            if(StaleMate==0)break;
            }
        }
        if(StaleMate==0)break;
        }
    if(StaleMate==0)break;
    }
}


