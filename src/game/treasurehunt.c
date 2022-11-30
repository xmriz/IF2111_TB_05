#include "treasurehunt.h"
#include <stdio.h>


void mainTreasureHunt(int *scoretreasurehunt){
    printf("Selamat datang di Treasure Hunt!\n\n");
    printf("Tentukan pilhanmu untuk menemukan harta karun!\n");
    printf("Men-generate peta dan harta karun. ");
    delay(1);
    printf(". ");
    delay(1);
    printf(". \n");
    TabGame ListQuestion;
    MakeEmptyGame(&ListQuestion);
    int n_line;
    char filepath[] = "..\\data\\fortreasurehunt.txt";
    readConfig(filepath, &ListQuestion, &n_line);
    char* str = (char*)malloc(sizeof(char)* 100);
    BinTree TreeAwal = genMapAwal();
    int nyawa = lives;
    boolean gameOver=false;
    printf("Tentukan path petualanganmu! (LEFT/RIGHT) \n"); // nih buat milih dia mau soal pertanyaan umum atau mtk
    printf("Masukkan pilihanmu: ");
    char* pilihan=scanstring();
    AddressT P=TreeAwal;
    do{
    if (isSameString(pilihan,"LEFT")){
        int n=pangkat2(depth); // kedalaman pohon
        P=LEFT(P);
        if (ROOT(P).random==1){
            BinTree TreePermainan = BuildMap(jmlSoal, n);
            // printPostorder(TreePermainan);
            play1(gameOver, scoretreasurehunt, &nyawa, TreePermainan, ListQuestion);
        } else {
            BinTree TreePermainan = BuildMap(6, n);
            // printPostorder(TreePermainan);
            play2(gameOver, scoretreasurehunt, &nyawa, TreePermainan);
        }
    } else if (isSameString(pilihan,"RIGHT")){
        int n=pangkat2(depth); // kedalaman pohon
        P=RIGHT(P);
        if (ROOT(P).random==1){
            BinTree TreePermainan = BuildMap(jmlSoal, n);
            // printPostorder(TreePermainan);
            play1(gameOver, scoretreasurehunt, &nyawa, TreePermainan, ListQuestion);
        } else {
            BinTree TreePermainan = BuildMap(6, n);
            // printPostorder(TreePermainan);
            play2(gameOver, scoretreasurehunt, &nyawa, TreePermainan);
        }
    } else {
        printf("Pilihan tidak valid. Silahkan coba lagi.\n");
    }
    } while (!isSameString(pilihan,"LEFT") && !isSameString(pilihan,"RIGHT"));
    if (nyawa==0){
        printf("Game Over! Nyawa kamu habis. \n");
    } 
    else{
        printf("Selamat! Kamu berhasil menamatkan map Treasure Hunt GG Geming\n");
        printf("Sisa nyawa kamu: %d\n", nyawa);
        printf("Mengonversi nyawa menjadi tambahan score ");
        printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
        *scoretreasurehunt+=(nyawa*3000);
    }
}

// pake grow map bukan build secara langsung soalnya kl build lebih lama dan ga efisien
BinTree BuildMap(int rentangrandom, int n){
    int ingfotreasure[]={999,0,999,0,0,-999,0,0,-999,0,999,0,0,-999};
    srand(time(NULL));
    AddressT P;
    int X,Y;
    BinTree R, L;
    int nL, nR;
    if (n == 0){
        return Nil;
    } else{
        X = (rand() + n) % rentangrandom +1;
        if (rentangrandom>50){
            if (X%2!=0){
                X+=1;
            }
        }
        ElTypeT node;
        node.random=X;
        Y = rand() % 14;
        Y = (Y+n) % 14;
        node.isTreasure=ingfotreasure[Y];
        P = newTreeNode(node);
        if (P != Nil){
            ROOT(P) = node;
            nL = n / 2;
            nR = n - nL - 1;
            L = BuildMap(rentangrandom, nL);
            R = BuildMap(rentangrandom, nR);
            LEFT(P) = L;
            RIGHT(P) = R;
        }
         return P;
   } 
}



BinTree genMapAwal (){
    BinTree t;
    t=(AddressT) malloc(sizeof(TreeNode));
    int left, right;
    right=rand() % 2 + 1;
    if (right==2){
        left=1;
    } else{
        left=2;
    }
    ElTypeT NodeL, NodeR;
    NodeL.isTreasure=0;
    NodeL.random=left;
    NodeR.isTreasure=0;
    NodeR.random=right;
    AddressT PL=newTreeNode(NodeL);
    AddressT PR=newTreeNode(NodeR);
    ElTypeT NodeAwal;
    NodeAwal.isTreasure=-1;
    NodeAwal.random=0;
    ROOT(t)=NodeAwal;
    LEFT(t)=PL;
    RIGHT(t)=PR;
    return (t);
}

void mathfunction(int random, boolean *isTrue){
    char operation[10];
    operation[0]='*';
    operation[1]='+';
    operation[2]='-';
    operation[3]='/';
    operation[4]='^';
    operation[5]='%';
    operation[6]='~';
    operation[7]='&';
    operation[8]='|';
    if (random==1){
        int x,y;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        int op=rand() % 9;
        printf("Berapakah hasil dari %d %c %d? ",x,operation[op],y);
        int jawaban=scanint();
        if (jawaban==func(x,y,operation[op])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    } else if (random==2){
        int x,y,z;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        z=rand() % 40 + 1;
        int op1=rand() % 9 + 1;
        int op2=rand() % 9 + 1;
        printf("Berapakah hasil dari (%d %c %d) %c %d? ",x,operation[op1],y,operation[op2],z);
        int jawaban=scanint();
        if (jawaban==func(func(x,y,operation[op1]),z,operation[op2])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    } else if (random==3){
        int x,y,z;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        z=rand() % 40 + 1;
        int op1=rand() % 9 + 1;
        int op2=rand() % 9 + 1;
        printf("Berapakah hasil dari ((%d %c %d) %c %d) %c %d? ",x,operation[op1],y,operation[op2],z,operation[op1],y);
        int jawaban=scanint();
        if (jawaban==func(func(func(x,y,operation[op1]),z,operation[op2]),y,operation[op1])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    } else if (random==4){
        int v,w,x,y,z;
        v=rand() % 40 + 1;
        w=rand() % 40 + 1;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        z=rand() % 40 + 1;
        int op1=rand() % 9 + 1;
        int op2=rand() % 9 + 1;
        int op3=rand() % 9 + 1;
        printf("Berapakah hasil dari (((%d %c %d) %c %d) %c %d) %c %d? ",v,operation[op1],w,operation[op2],x,operation[op3],y,operation[op1],z);
        int jawaban=scanint();
        if (jawaban==func(func(func(func(v,w,operation[op1]),x,operation[op2]),y,operation[op3]),z,operation[op1])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    } else if (random==5){
        int v,w,x,y,z;
        v=rand() % 40 + 1;
        w=rand() % 40 + 1;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        z=rand() % 40 + 1;
        int op1=rand() % 9 + 1;
        int op2=rand() % 9 + 1;
        int op3=rand() % 9 + 1;
        printf("Berapakah hasil dari ((((%d %c %d) %c %d) %c %d) %c %d) %c %d? ",v,operation[op1],w,operation[op2],x,operation[op3],y,operation[op1],z,operation[op2],w);
        int jawaban=scanint();
        if (jawaban==func(func(func(func(func(v,w,operation[op1]),x,operation[op2]),y,operation[op3]),z,operation[op1]),w,operation[op2])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    } else if (random==6){
        int v,w,x,y,z;
        v=rand() % 40 + 1;
        w=rand() % 40 + 1;
        x=rand() % 40 + 1;
        y=rand() % 40 + 1;
        z=rand() % 40 + 1;
        int op1=rand() % 9 + 1;
        int op2=rand() % 9 + 1;
        int op3=rand() % 9 + 1;
        printf("Berapakah hasil dari (((((%d %c %d) %c %d) %c %d) %c %d) %c %d) %c %d? ",v,operation[op1],w,operation[op2],x,operation[op3],y,operation[op1],z,operation[op2],w,operation[op3],x);
        int jawaban=scanint();
        if (jawaban==func(func(func(func(func(func(v,w,operation[op1]),x,operation[op2]),y,operation[op3]),z,operation[op1]),w,operation[op2]),x,operation[op3])){
            printf("Jawaban kamu benar!\n");
            *isTrue=true;
        } else{
            printf("Jawaban kamu salah!\n");
            *isTrue=false;
        }
    }
}

int func(int op1, int op2, char op){
    int hasil;
    switch (op){
        case '*':
            hasil=op1*op2;
            break;
        case '+':
            hasil=op1+op2;
            break;
        case '-':
            hasil=op1-op2;
            break;
        case '/':
            hasil=op1/op2;
            break;
        case '^':
            hasil=op1^op2;
            break;
        case '%':
            hasil=op1%op2;
            break;
        case '~':
            hasil=~op1;
            break;
        case '&':
            hasil=op1&op2;
            break;
        case '|':
            hasil=op1|op2;
            break;
    }
    return hasil;
}

void QuestionandAnswer(boolean *isTrue,  int random, TabGame listPertanyaan){
    printf("Jawablah pertanyaan berikut!\n\n");
    printkalimat(listPertanyaan.TG[random]);
    char* jawaban=scanstring();
    char* jawabanAsli = (char*)malloc(sizeof(char)* 100);
    KalimatToString(listPertanyaan.TG[random+1], jawabanAsli);
    if (isSameString(jawaban,jawabanAsli)){
        printf("Jawaban kamu benar!\n");
        *isTrue=true;
    } else{
        printf("Jawaban kamu salah!\n");
        printf("Jawaban yang benar adalah %s\n",jawabanAsli);
        *isTrue=false;
    }
}

void play1(boolean gameOver, int *score, int *nyawa, BinTree tree, TabGame listPertanyaan){
    printf("\nBersiaplah dengan tantangan pada path yang kamu pilih!\n");
    printf("Kumpulkan emas sebanyak-banyaknya dan berhati-hatilah dalam melangkah!\n");
    printf("Kamu memiliki %d nyawa. Jangan sampai menginjak trap\n",lives);
    printf("\nPetualangan dimulai!\n");
    AddressT P=tree;
    boolean isEmpty=false;
    while (!isEmpty && *nyawa!=0){
        printf("Masukkan pilihanmu: ");
        char* pilihan=scanstring();
        if (isSameString(pilihan,"LEFT")){
            P=LEFT(P);
            if (P!=NULL){
                if (ROOT(P).isTreasure==999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("Selamat kamu menemukan treasure!\n");
                    printf("\nScore kamu bertambah 1000\n");
                    *score+=1000;   
                } else if (ROOT(P).isTreasure==-999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("\nOops! Kamu menginjak trap!\n");
                    printf("\nNyawamu berkurang 1\n");
                    *nyawa-=1;
                } else {
                    boolean istrue;
                    QuestionandAnswer(&istrue, ROOT(P).random, listPertanyaan);
                    if (istrue){
                        *score += 100;
                    } else{
                        *score -=10;
                    }
                }
            } else{
                isEmpty=true;
            }
        } else if (isSameString(pilihan,"RIGHT")){
            P=RIGHT(P); 
            if (P!=NULL){
                if (ROOT(P).isTreasure==999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("Selamat kamu menemukan treasure!\n");
                    printf("\nScore kamu bertambah 1000\n");
                    *score+=1000;
                } else if (ROOT(P).isTreasure==-999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("\nOops! Kamu menginjak trap!\n");
                    printf("\nNyawamu berkurang 1\n");
                    *nyawa-=1;
                } else {
                    boolean istrue;
                    QuestionandAnswer(&istrue, ROOT(P).random, listPertanyaan);
                    if (istrue){
                        *score += 100;
                    } else{
                        *score -=10;
                    }
                }
            } else{
                isEmpty=true;
            }
            } else {
                    printf("Pilihan tidak valid. Silahkan coba lagi.\n");
            }
        }
        
    }


void play2(boolean gameOver, int *score, int *nyawa, BinTree tree){
    printf("\nBersiaplah dengan tantangan pada path yang kamu pilih!\n");
    printf("Kumpulkan emas sebanyak-banyaknya dan berhati-hatilah dalam melangkah!\n");
    printf("Kamu memiliki %d nyawa. Jangan sampai menginjak trap\n", lives);
    printf("\nPetualangan dimulai!\n");
    AddressT P=tree;
    boolean isEmpty=false;
    while (!isEmpty && *nyawa!=0){
        printf("Masukkan pilihanmu: ");
        char* pilihan=scanstring();
        if (isSameString(pilihan,"LEFT")){
            P=LEFT(P);
            if (P!=NULL){
                if (ROOT(P).isTreasure==999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("Selamat kamu menemukan treasure!\n");
                    printf("\nScore kamu bertambah 1000\n");
                    *score+=1000;
                } else if (ROOT(P).isTreasure==-999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("\nOops! Kamu menginjak trap!\n");
                    printf("\nNyawamu berkurang 1\n");
                    *nyawa-=1;
                } else {
                    boolean istrue;
                    mathfunction(ROOT(P).random,&istrue);
                    if (istrue){
                        *score += 100;
                    } else{
                        *score -=10;
                    }
                }
            } else {
                isEmpty=true;
            }
        } else if (isSameString(pilihan,"RIGHT")){
            P=RIGHT(P);   
            if (P!=NULL) {
                if (ROOT(P).isTreasure==999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("Selamat kamu menemukan treasure!\n");
                    printf("\nScore kamu bertambah 1000\n");
                    *score+=1000;
                } else if (ROOT(P).isTreasure==-999){
                    printf("Tunggu, kamu menginjak sesuatu!\n");
                    printf(". "); delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(". \n");
                    printf("\nOops! Kamu menginjak trap!\n");
                    printf("\nNyawamu berkurang 1\n");
                    *nyawa-=1;
                } else {
                    boolean istrue;
                    mathfunction(ROOT(P).random, &istrue);
                    if (istrue){
                        *score += 100;
                    } else{
                        *score -=10;
                    }
                }
            } else {
                isEmpty=true;
            }
        } else {
                    printf("Pilihan tidak valid. Silahkan coba lagi.\n");
                }
        }
    }
        

void guideline(){
    printf("=======================================================================================================\n");
    printf("|                                    GUIDE BERMAIN TREASURE HUNT                                      |\n");
    printf("| Pada game Treasure Hunt, kamu memiliki misi untuk mengumpulkan emas sebanyak-banyaknya              |\n");
    printf("| Pada setiap step (LEFT/RIGHT) kamu berkemungkinan mendapatkan treasure, trap, atau tidak keduanya   |\n");
    printf("| Saat kamu tidak mendapatkan treasure atau trap, kami menantang kamu untuk menjawab pertanyaan,      |\n");
    printf("| jika kamu bisa menjawab pertanyaan tersebut, kamu mendapatkan emas, jika tidak maka emasmu berkurang|\n");
    printf("| Saat kamu mendapat treasure, emasmu akan bertambah secara signifikan                                |\n");
    printf("| Sebaliknya jika kamu terkena trap, nyawamu berkurang 1                                              |\n");
    printf("| Kamu hanya memiliki %s nyawa, jika kamu terkena trap %s kali, kamu akan mati </3                      |\n",lives,lives);
    printf("=======================================================================================================\n");
}

int pangkat2(int n){
    int hasil=1;
    for (int i=0;i<n;i++){
        hasil*=2;
    }
    return hasil;
}