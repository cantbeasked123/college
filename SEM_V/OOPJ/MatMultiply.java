class Mat{
    static int[][] multiplyMat(int m1[][],int m2[][],int c1,int c2)
{
    int temp[][]= new int[m1.length][c2];
    int row1=m1.length,row2=m2.length;
    for(int i=0;i<row1;i++)
    {
            for(int j=0;j<c2;j++)
            {
                    for(int k=0;i<row2;k++)
                    {
                        temp[i][j]+=m1[j][k]*m2[k][j];
                    }
            }
    }
    return temp;
}

public static void main(String[] args)
{
    int a[][]={{1,1,1},{1,1,1}};
    int b[][]={{1,1},{1,1},{1,1}};
    int c[][];
    
    c=Mat.multiplyMat(a,b,3,2);
     for(int i=0;i<c.length;i++)
    {
            for(int j=0;j<c[0].length;j++)
            {
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
    }
}

}
