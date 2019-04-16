/*
Nama        : Shania Salsabila
NPM         : 140810180014
Deskripsi   : excercise-04
Tahun       : 2019
*/
#include <iostream>

using namespace std;

struct Contact{
     char name[10];
     char phone[12];
     Contact* nextcontact;
};

struct Index{
     char index[1];
     Contact* FirstContact;
     Index* next;
};

typedef Index* pointerInd;
typedef Contact* pointerCon;
typedef pointerInd listInd;

void createListInd(listInd& First){
    First = NULL;
}
void createElmtInd(pointerInd& pBaru){
    pBaru = new Index;
    cout<<"Masukkan Index:";
    cin>>pBaru->index;
    pBaru->next = NULL;
    pBaru->FirstContact = NULL;
}
void createElmtContact(pointerCon& pBaru){
    pBaru = new Contact;
    cout<<"Masukkan Nama  : ";
    cin>>pBaru->name;
    cout<<"Masukkan Nomor : ";
    cin>>pBaru->phone;
    pBaru->nextcontact = NULL;
}
void traversalInd(listInd First){
    pointerInd pBantu;
    pBantu = First;
    cout<<"Index :"<<endl;
    while(pBantu!=NULL){
        cout<<"|- "<<pBantu->index<<endl;
        pBantu = pBantu->next;
    }
}
void linearSearch(listInd First,char key[20],int& status,pointerInd& pCari){
    status = 0;
    pCari = First;
    while(status==0 && pCari!=NULL){
        if((pCari->index,key)==0){
            status = 1;
        }
        else{
            pCari = pCari->next;
        }
    }
}
void insertFirstInd(listInd& First,pointerInd pBaru){
     if(First==NULL){
        First = pBaru;
     }
     else{
        pBaru->next = First;
        First = pBaru;
     }
}
void deleteFirstInd(listInd& First,pointerInd pHapus){
     if(First==NULL){
        cout<<"Tidak ada yang dihapus"<<endl;
     }
     else if(First->next==NULL){
        pHapus = First;
        First = NULL;
     }
     else{
        pHapus = First;
        First = pHapus->next;
        First->next = NULL;
    }
}
void insertFirstContact(listInd& First,char key[20],pointerCon pBaru){
     pointerInd pInd;
     int ketemu;
     cout<<"Insert Index yang di cari: ";
     cin>>key;
     linearSearch(First,key,ketemu,pInd);
     if(ketemu){
          cout<<"Ditemukan dengan Index : "<<pInd->index<<endl;
          if(pInd->FirstContact==NULL){
            pInd->FirstContact = pBaru;
          }
          else{
            pBaru->nextcontact = pInd->FirstContact;
            pInd->FirstContact = pBaru;
          }
     }
     else{
      cout<<"Nama Divisi tidak di temukan"<<endl;
     }
}
void deleteFirstContact(listInd& First,char key[20],pointerCon& pHapus ){
    int ketemu;
    pointerInd pInd;
    cout<<"Insert Index yang di cari: ";
    cin>>key;
    linearSearch(First,key,ketemu,pInd);

    if(ketemu){
        cout<<"Ditemukan dengan nama :"<<pInd->index;
        if(pInd->FirstContact==NULL){
            cout<<"Tidak ada yang di hapus"<<endl;
        }
        else if(pInd->FirstContact->nextcontact==NULL){
            pHapus = pInd->FirstContact;
            pInd->FirstContact = NULL;
        }
        else{
            pHapus = pInd->FirstContact;
            pInd->FirstContact = pInd->FirstContact->nextcontact;
            pHapus->nextcontact = NULL;
        }
    }
     else{
        cout<<"Nama Index tidak di temukan"<<endl;
     }

}
void traversalIndContact(listInd First){
    pointerInd pBantuInd;
    pointerCon pBantuCon;
    cout<<"Traversal Index"<<endl;
    pBantuInd=First;
    while (pBantuInd!=NULL){
        cout<<"|- "<<pBantuInd->index<<endl;
        pBantuCon = pBantuInd->FirstContact;
        while (pBantuCon!=NULL) {
            cout<<"\t|- "<<pBantuCon->name<<" / "<<pBantuCon->phone<<endl;
            pBantuCon = pBantuCon->nextcontact;
        }
        pBantuInd = pBantuInd->next;
    }
}

int main()
{
    listInd q;
    int nd,nk,menu;
    char key [20];
    pointerInd pd,pc,phd;
    pointerCon pk,phk;
    createListInd(q);

    do{
        system("cls");
        cout<<"|=====================|"<<endl;
        cout<<"|    Tampilan Menu    |"<<endl;
        cout<<"|1.Insert Index       |"<<endl;
        cout<<"|2.Insert Nama        |"<<endl;
        cout<<"|3.Delete First Index |"<<endl;
        cout<<"|4.Delete First Nama  |"<<endl;
        cout<<"|5.Update Phone Book  |"<<endl;
        cout<<"|6.Exit               |"<<endl;
        cout<<"|=====================|"<<endl;
        cout<<"Pilihan:";
        cin>>menu;
        switch(menu){
        case 1 :
            cout<<"Masukan banyak Index : ";
            cin>>nd;
            for(int i=0;i<nd;i++){
                createElmtInd(pd);
                insertFirstInd(q,pd);
            }
        break;

        case 2 :
            cout<<"Masukan banyak Nama :";
            cin>>nk;
            traversalInd(q);
            for(int i=0;i<nk;i++){
                createElmtContact(pk);
                insertFirstContact(q,key,pk);
            }
        break;

        case 3 :
            deleteFirstInd(q,phd);
            traversalInd(q);
        break;

        case 4:
            deleteFirstContact(q,key,phk);
            traversalIndContact(q);
        break;

        case 5 :
            traversalIndContact(q);
        break;

        default :
            exit(0);
        }
        system("pause");
    }while(menu!=6);
}
