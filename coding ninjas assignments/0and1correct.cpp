
void sortZeroesAndOne(int a[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Update in the given array itself. Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */

    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]==0)
        {
            i++;
        }
        else if(a[j]==1)
        {
            j--;
        }
        else {
            int t =a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
}