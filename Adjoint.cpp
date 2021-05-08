		
#include<bits/stdc++.h>
using namespace std;

/*Function to calculat the cofactor of the matrix, used in adjoint */
vector<vector<int>> getCofactor(vector<vector<int>> mat, int p, int q, int n)
{
 	vector<vector<int>> temp((mat.size()-1),vector<int>(mat.size()-1));

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
	return temp;
}
/* Recursive function for finding determinant of matrix mat of n dimension */
int determinantOfMatrix(vector<vector<int>> mat, int n)
{
	int D = 0; // Initialize result

	// Base case : if matrix contains single element
	if (n == 1)
		return mat[0][0];
	vector<vector<int>> Temp((mat.size()-1),vector<int>(mat.size()-1));

	int sign = 1; // To store sign multiplier

	// Iterate for each element of first row
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of mat[0][f]
	Temp=getCofactor(mat, 0, f, n);
		D += sign * mat[0][f]* determinantOfMatrix(Temp, n - 1);

		// terms are to be added with alternate sign
		sign = -sign;
	}
	return D;
}

/***********************************************************************/
// Function to get adjoint of A[N][N] in adj[N][N].
vector<vector<int>> adjoint(vector<vector<int>> A,int n)
{
	vector<vector<int>> adj(n,vector<int>(n));

	if (n == 1)
	{
		adj[0][0] = 1;
		return adj;
	}

	// temp is used to store cofactors of A[][]
	int sign = 1;
	vector<vector<int>> temp(n,vector<int>(n));

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			// Get cofactor of A[i][j]
			temp=getCofactor(A, i, j, n);

			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i+j)%2==0)? 1: -1;

			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j][i] = (sign)*(determinantOfMatrix(temp, n-1));
		}
	}
	return adj;
}

int main()
{

	return 0;
}
