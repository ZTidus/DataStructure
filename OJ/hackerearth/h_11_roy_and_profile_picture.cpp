// h_11_roy_and_profile_picture
#include <cstdio>
int main(){
    int length, n; // Number of photos
    scanf("%d\n%d", &length, &n);
    for(int i = 0; i < n; i++){
        int width, height;
        scanf("%d%d", &width, &height);
        if(width < length || height < length) printf("UPLOAD ANOTHER\n");
        else if(width == height) printf("ACCEPTED\n");
        else printf("CROP IT\n");
    }
    return 0;
}