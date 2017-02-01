#include <iostream>
//#include <algoritm>
#define MAX 100000
using namespace std;
void voltea(int tortita[], int volteo){
    int c, i ,j;
    for(i=0, j=volteo-1 ; i<j ; i++, j--)
    {
        c = tortita[i];
        tortita[i] = tortita[j];
        tortita[j] = c;
    }
}

int michelon(int tortita[], int tortitas ,int volteo[], int volteos){
    for(int i=0;i<volteos;i++){
        voltea(tortita+(tortitas-volteo[i]), volteo[i]);
    }
    return tortita[tortitas-1];
}

bool solve(){
	int tortita[MAX];
	int volteo[MAX];
	int volteos, tortitas,t, v = 0;
	do{
	t=v=volteos=tortitas=0;
	cin >> t;
	while(t != -1){
        tortita[tortitas]=t;
        tortitas++;
        cin>>t;
	}
	cin >> volteos;
	if (tortitas != 0){
        for (int i=0;i < volteos; i++){
            cin >> v;
            if (v>=0&&v<=tortitas)
            volteo[i]=v;
        }

        cout << michelon(tortita, tortitas, volteo, volteos) << endl;
	}
	}while(tortitas != 0);
	return false;
}
int main(int argc, char **args){
	while(solve());
	return 0;
}
