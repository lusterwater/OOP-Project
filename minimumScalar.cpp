#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
long int minimumScalar (vector<long int> vector1, vector<long int>  vector2)
{

    int temp=0;
    int long result=0;
    for(int i = 0; i<vector1.size(); i++)
    {
        for(int j = 0; j < vector1.size()-1;j++)
        {
            if(vector1[j]<vector1[j+1])
            {
                temp = vector1[j];
                vector1[j] = vector1[j+1];
                vector1[j+1] = temp;
            }
        }
    }

    for(int i = 0; i<vector2.size(); i++)
    {
        for(int j = 0; j < vector2.size()-1;j++)
        {
            if(vector2[j]>vector2[j+1])
            {
                temp = vector2[j];
                vector2[j] = vector2[j+1];
                vector2[j+1] = temp;
            }
        }
    }

    for(int i = 0; i<vector1.size(); i++)
    {
        result = result + (vector1[i]*vector2[i]);
    }
    return result;
}
int main()
{
    ifstream streamIn;
    vector<long int> vec1;
    vector<long int> vec2;
    streamIn.open("realtest.txt");

    int sizeOfCase,cases,numbers;
    int counter=0;
    streamIn >> cases;
    streamIn.ignore();

    while(!streamIn.eof()&&counter!=cases)
    {
        counter++;
        streamIn >> sizeOfCase;
        streamIn.ignore();
        for(int i = 0; i < sizeOfCase; i++ )
        {
            streamIn >> numbers;
            vec1.push_back(numbers);
        }
        streamIn.ignore();
        for(int i = 0; i < sizeOfCase; i++ )
        {
            streamIn >> numbers;
            vec2.push_back(numbers);
        }
        streamIn.ignore();
        cout<<"Case#" << counter << ": " <<minimumScalar(vec1,vec2)<<endl;
        vec1.clear();
        vec2.clear();
    }

    return 0;
}
