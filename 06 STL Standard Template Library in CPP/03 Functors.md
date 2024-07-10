class functorOne{
public:
bool operatoes()(int a, int b){
return a >b;
}
}

int main(){
functorOne cmp ;

    if( cmp(15,10)){
        cout<<"True"<<endl;
    }

}
