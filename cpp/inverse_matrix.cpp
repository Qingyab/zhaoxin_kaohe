#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Inverse{
public:
    Inverse(){}

    void inverse(vector<vector<float>>& matrix,int k){

        vector<vector<float>> _matrix=standard(matrix,k);

        if(strange(matrix,k)){
            reverse(matrix,k);
        }
        else{
            cout << "矩阵不可逆" << endl;
        }
    }

private:
    vector<vector<float>> standard(const vector<vector<float>>& matrix,int k){
        vector<vector<float>> _matrix;
        for(int i=0;i<k;i++){
            for(int j=0;j<2*k;j++){
                if(j<k){
                    _matrix[i][j]=matrix[i][j];
                }
                else if(j-k==k){
                    _matrix[i][j]=1.0;
                }
                else{
                    _matrix[i][j]=0.0;
                }
            }
        }

        return _matrix;
    }

    bool strange(vector<vector<float>> matrix,int k){
        int n1=k;
        for(int m=0;m<n1-1;m++){
            float k=float(matrix[m+1][m]/matrix[m][m]);
            for(int m1=1;m1<n1-m;m1++){
                for(int n=m;n<2*n1;n++){
                    matrix[m1][n]=float(matrix[m1][n]-k*matrix[m1-1][n]);
                }
            }
        }

        for(int m=0;m<n1;m++){
            if(matrix[m][m]==0){
                return false;
            }
        }

        return true;
    }

    void reverse(vector<vector<float>>& matrix,int k){
        int l=k;
        int n=l-1;
        while(n>=0){
            for(int i=n+1;i<l;i++){
                int k=float(matrix[n][i]/matrix[i][i]);
                for(int j=n+1;j<2*l;j++){
                    matrix[n][j]=matrix[n][j]-k*matrix[i][j];
                }
                n-=1;
            }
        }

        for(int i=0;i<l;i++){
            int k=float(1/matrix[i][i]);
            for(int j=i;i<2*l;j++){
                matrix[i][j]=k*matrix[i][j];
            }
        }

        for(int m=0;m<l;m++){
            for(int n=0;n<2*l;n++){
                cout << setw(7) << setprecision(5) <<matrix[m][n];
            }
            cout << endl;
        }
    }
};


int main(void){
    vector<vector<float>> matrix;
    int k;
    cout << "请输入方针的阶数" << endl;
    cin >> k;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin >> matrix[i][j];
        }
    }
    Inverse Solution;
    Solution.inverse(matrix,k);

    return 0;
}