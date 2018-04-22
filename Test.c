#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 10000
char s1[max],s2[max],s[max];
int d=0,mark[max];
void ChangeForm(char s3[]){
    int j,n=strlen(s3),i=n;
    while (i>0) {
        while (s3[i]!=' '&&i>0) i--;
        if (s3[i]==' '){
            for (j=i;j<n;j++) s3[j]=s3[j+1];
            n--;
        }
    }
    for (i=0;i<n;i++) if (s3[i]>'A'&&s3[i]<'Z') s3[i]+=32;
}
int Checkingoff(){
    int a[max];
    int i,j,n=strlen(s1);
    if (strlen(s1)!=strlen(s2)) return 0;
    for (i=0;i<strlen(s1);i++) a[i]=1;
    i=0;
    while (i<n) {
        for (j=0;j<n;j++)
        if (a[j]==1&&s1[i]==s2[j]){
                a[j]=0;
                break;
        }
        i++;
    }
    for (i=0;i<n;i++) if (a[i]==1) return 0;
    return 1;
}
void Sort(char s3[]){
    int i,j,n=strlen(s3);
    char x;
    for (i=0;i<n-1;i++){
        int min =i;
        for (j=i+1;j<n;j++)
            if (s3[j]<s3[min]) min=j;
        x=s3[min];
        s3[min]=s3[i];
        s3[i]=x;
    }
}
int Compare(){
    int i;
    if (strlen(s1)!=strlen(s2)) return 0;
    Sort(s1);
    Sort(s2);
    for (i=0;i<strlen(s1);i++)
        if (s1[i]!=s2[i]) return 0;
    return 1;
}
int CountAndCompare(){
    int i,n=strlen(s1),a[26],b[26];
    for (i=0;i<n;i++) {a[i]=0;b[i]=0;};
    if (strlen(s1)!=strlen(s2)) return 0;
    for (i=0;i<n;i++) a[s1[i]-97]++;
    for (i=0;i<n;i++) b[s2[i]-97]++;
    for (i=0;i<n;i++) if (a[i]!=b[i]) return 0;
    return 1;
}
int check(){
    int i;
    for (i=0;i<strlen(s1);i++)
        if (s[i]!=s2[i]) return 0;
    return 1;
}
void CleanOut(int x){
    int i;
    for (i=0;i<strlen(s1);i++){
        if (mark[i]==0) {
            s[x]=s1[i];
            mark[i]=100;
            if (x==strlen(s1)-1&&check()==1) d=1;
            CleanOut(x+1);
            mark[i]=0;
        }
    }
}
int main(){
    fflush(stdin);
    gets(s1);
    gets(s2);
    ChangeForm(s1);ChangeForm(s2);
    //CleanOut(0);printf("%d",d);
   // printf("%d",Checkingoff());
    //printf("%d",CountAndCompare());
    //printf("%d",Compare());
    return 0;
}
