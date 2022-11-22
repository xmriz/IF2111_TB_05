#include <stdio.h>
#include "setGame.h"

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    S->Count=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    // KAMUS LOKAL
    // ALGORITMA
    return (S.Count==Nil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    // KAMUS LOKAL
    // ALGORITMA
    return(S.Count==MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    // KAMUS LOKAL
    // ALGORITMA
    if (!IsMember(*S,Elmt)){
        S->Count++;
        copyKalimat(Elmt,&((*S).Elements[(*S).Count-1]));
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    // KAMUS LOKAL
    int i=0,x;
    boolean found=false;
    // ALGORITMA
    if (IsMember((*S),Elmt)){
        while (i<S->Count && !found){
            if (isKalimatSame(S->Elements[i],Elmt)){
                found=true;
            } else{
                i++;   
            }   
        }
        for (x=i; x<S->Count-1; x++){
            copyKalimat(S->Elements[i+1],&(S->Elements[i]));
        }
        S->Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    // KAMUS LOKAL
    int i=0;
    boolean found=false;
    // ALGORITMA
    while (i<S.Count && !found){
            if (isKalimatSame(S.Elements[i],Elmt)){
                found=true;
            } else{
                i++;   
            }   
        }
    return(found);
    }
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2){
	int i;
	Set s3; 
    CreateEmpty(&s3);
	for (i = 0; i < s1.Count; i++) {
		if (!IsMember(s3, s1.Elements[i])){
            Insert(&s3, s1.Elements[i]);
        } 
	}
	for (i = 0; i < s2.Count; i++) {
		if (!IsMember(s3, s2.Elements[i])){
            Insert(&s3, s2.Elements[i]);
        } 
	}
	return s3;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2){
    Set s3;
    CreateEmpty(&s3);
    int i,count;
    if (s1.Count>=s2.Count){
        count=s1.Count;
    } else{
        count=s2.Count;
    }
    for (i=0;i<count;i++){
        if (IsMember(s1,s2.Elements[i])){
            Insert(&s3,s2.Elements[i]);
        }
    }
    return(s3);
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2){
    Set s3, sn;
    int i;
    CreateEmpty(&s3);
    CreateEmpty(&sn);
    sn=SetIntersection(s1,s2);
    for (i=0;i<s1.Count; i++){
        if (!IsMember(sn,s1.Elements[i])){
            Insert(&s3,s1.Elements[i]);
        }
    }
    for (i=0;i<s2.Count; i++){
        if (!IsMember(sn,s2.Elements[i])){
            Insert(&s3,s2.Elements[i]);
        }
    }
    return(s3);
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2){
    Set min;
    int i,el;
    CreateEmpty(&min);
	for (i = 0; i < s1.Count; i++) {
		if (!IsMember(s2, s1.Elements[i])){
            Insert(&min, s1.Elements[i]);}
	}
    return(min);
}