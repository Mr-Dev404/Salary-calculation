#include<iostream>
#include<iomanip>
#include<unistd.h>
#define rozane 238782
#define rsaat 29859
#define BIME 0.07
#define MALIAT 0.10
#define MIN_HOGHOGH 8000000
using namespace std;

void show(){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"|        wellcome to Mr-Dv404 program  :)              |"<<endl;
    cout<<"|                                                      |"<<endl;
    cout<<"| [1] afzodan karmand                                  |"<<endl;
    cout<<"| [2] mohasebe hoghogh                                 |"<<endl;
    cout<<"| [3] mohasebe hoghogh hame                            |"<<endl;
    cout<<"| [4] Exit program                                     |"<<endl;
    cout<<"|                                                      |"<<endl;
    cout<<"|        Github : https://github.com/Mr-Dev404         |"<<endl;
    cout<<"--------------------------------------------------------\n"<<endl;
    cout<<">> ";
}

class karmand{
public:
    float ho,id,roz,saat=0,nobat,shab,ezafe,sshab,vv,s1=0,s2=0,s3=0,s4=0,fs1,fs2,fs3,fs4,fshab;
    float bime,maliat,kolhoghogh,hoghogh_nahaei;
    string v;
    void get(int i){
        system("cls");
        cout<<"Enter Id Krmand shomare["<<i+1<<"]:";
        cin>>id;
        cout<<"Enter tedad rozkarkard Krmandshomare["<<i+1<<"]:";
        cin>>roz;
        cout<<"Enter saat ezafekari Krmand shomare["<<i+1<<"]:";
        cin>>saat;
        ho=(roz*rozane);
        ezafe=(ho*0.4*saat);
        cout<<"Aya karmand shoma shabkar hast ya nobat karydare:{shab,nobat,none} ";
        cin>>v;
        if(v=="shab"){
            cout<<"chand saat shab kari dasht? :";
            cin>>sshab;
            fshab=(sshab*rsaat*0.35);
        }
        else if(v=="nobat"){
            cout<<"sift sobh ta zohr ya shab ta zohr ya badazohr ya shab{1/2/3/4}? ";
            cin>>vv;
            if(vv==1){
                cout<<"chand saat kar karde?:";
                cin>>s1;
                fs1=(s1*rsaat*0.10);
            }
            else if(vv==2){
                cout<<"chand saat kar karde?:";
                cin>>s2;
                fs2=(s2*rsaat*0.225);
            }
            else if(vv==3){
                cout<<"chand saat kar karde?:";
                cin>>s3;
                fs3=(s3*rsaat*0.225);
            }
            else if(vv==4){
                cout<<"chand saat kar karde?:";
                cin>>s4;
                fs4=(s4*rsaat*0.15);
            }
            else{
                cout<<"Error!";
            }
        }
        kolhoghogh=ho+ezafe+fshab+fs1+fs2+fs3+fs4;
        bime=kolhoghogh*BIME;
        maliat=kolhoghogh*MALIAT;
        hoghogh_nahaei=kolhoghogh-bime-maliat;
        if(hoghogh_nahaei<MIN_HOGHOGH){
            hoghogh_nahaei=MIN_HOGHOGH;
        }
    }
    void namayesh(int i){
        cout<<fixed<<setprecision(10);
        cout<<"hoghogh kol karmand shomare["<<i+1<<"]: "<<kolhoghogh<<endl;
        cout<<"bime karmand [ "<<i+1<<"]: "<<bime<<", maliat: "<<maliat<<endl;
        cout<<"hoghogh nahai karmand shomare["<<i+1<<"]: "<<hoghogh_nahaei<<endl;
        cout<<"hoghogh paye karmand shomare["<<i+1<<"]: "<<ho<<endl;
        cout<<"\npls waiting :0 ";
        sleep(7);
        system("cls");
    }
};

const int MAX_KARMAND=100;
karmand d[MAX_KARMAND];
int l=1;

int main(){
    int c;
    while(true){
        show();
        cin>>c;
        if(c==1){
            system("cls");
            cout<<"chand ta Karmand Dari?:";
            cin>>l;
            system("cls");
            for(int i=0;i<l;i++){
                d[i].get(i);
            }
        }
        else if(c==2){
            int k;
            system("cls");
            cout<<"id karmand ra vared konid : ";
            cin>>k;
            for(int i=0;i<l;i++){
                if(d[i].id==k){
                    d[i].namayesh(i);
                }
            }
        }
        else if(c==3){
            system("cls");
            float sum=0;
            for(int i=0;i<l;i++){
                d[i].namayesh(i);
                sum+=d[i].hoghogh_nahaei;
            }
            cout<<"Majmoe Hoghogh Karmandan: "<<sum<<endl;
            sleep(5);
            system("cls");
        }
        else if(c==4){
            exit(0);
        }
    }
}
