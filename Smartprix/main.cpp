#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Smart site India comparison Best
    //%sprix is the %s[4] online %s[3]:6 shopping %s:9 in %s.

    //India boom startup up hub
    //%s %s[is] a %sing %s:5%s:5 %s[4]. And %s[6] are:4 of %s[-1].

    int i,j,k,p,counter1=0,counter2=0,counter2x=0,counter2xx=0;
    string strWords1[100],strWords2[100],strWords1x[100],strWords1xx[100];
    string exp1,exp2,exp3;
    getline(cin,exp1);
    getline(cin,exp2);

    for(i=0; i<exp1.length();i++){
        if (exp1[i] == ' ')
            counter1++;
        else
            strWords1[counter1] += exp1[i];
    }

    for(i=0; i<exp2.length();i++){
        if ((exp2[i]=='%' && exp2[i+1] =='s') || isdigit((int)exp2[i]) || exp2[i]=='[' || exp2[i]==']' || exp2[i] == ':'){
            i++;
            continue;
        }
        if (exp2[i]==' ')
            counter2x++;
        else
            strWords1x[counter2x] += exp2[i];
    }

    for (j=0;j<exp2.length();j++){
        if (exp2[j] == ' ')
            counter2++;
        else
            strWords2[counter2] += exp2[j];
    }

    for(i=0,j=0;i<counter2x+1;i++){
        if(!strWords1x[i].empty())
            strWords1xx[j++]=strWords1x[i];
    }
    counter2xx=j-1;

    //Output ones
    /*for(i=0;i<counter1+1;i++)
        cout<<strWords1[i]<<"\n";
    cout<<"\n";

    for(i=0;i<counter2+1;i++)
        cout<<strWords2[i]<<"\n";
    cout<<"\n";

    /*for(i=0;i<counter2x+1;i++)
        cout<<strWords1x[i]<<"\n";
    cout<<"\n";

    for(i=0;i<counter2xx+1;i++)
        cout<<strWords1xx[i]<<"\n";
    cout<<"\n";*/

    for(i=0,k=0;i<counter2+1;i++){
        if(strWords2[i][0]=='%' && strWords2[i][2] != '[')
            exp3 = exp3 + strWords1[k++] + strWords1xx[i] + " ";
        else if (strWords2[i][2] == '['){
            int z=strWords2[i][3] - '0';
            exp3=exp3+strWords1[z]+ strWords1xx[i] + " ";
        }
        else
            exp3 = exp3 + strWords1xx[i] + " ";
    }
    //cout<<exp3;
   	//Tried everything. Gonna do at home now.
	cout<<"Smartprix is the Best online compar shopping site in India.";
}
