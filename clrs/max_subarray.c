

#include <stdio.h>


struct max_entity
{
    int max_left_idx;
    int max_right_idx;
    int max_value;
};

typedef struct max_entity max_entity;

max_entity find_cross_max(int array[], int start, int mid, int end){
    int max_left = -65535;
    int sum = 0;
    int i = mid;
    int max_left_idx=-1;
    for(;i>=start;i--){
        sum += array[i];
        if(sum > max_left){
            max_left_idx = i;
            max_left = sum;
        }
    }

    int max_right = -65535;
    sum = 0;
    int j = mid+1;
    int max_right_idx = -1;
    for(;j<=end;j++){
        sum += array[j];
        if(sum > max_right){
            max_right = sum;
            max_right_idx = j;
        }
    }

    max_entity entity;
    entity.max_left_idx = max_left_idx;
    entity.max_right_idx = max_right_idx;
    entity.max_value = max_left + max_right;
    return entity;

}

max_entity find_max_sub_array(int array[], int start, int end){
    max_entity entity;
    if(start == end){
        entity.max_left_idx = start;
        entity.max_right_idx = end;
        entity.max_value = array[start];
        return entity;
    }else{
        int mid = (start + end) / 2;
        max_entity max_left = find_max_sub_array(array, start, mid);
        max_entity max_right = find_max_sub_array(array, mid+1, end);
        max_entity max_cross = find_cross_max(array, start, mid, end);
        if(max_left.max_value >= max_cross.max_value && max_left.max_value >= max_right.max_value){
            return max_left;
        }
        else if(max_right.max_value >= max_left.max_value && max_right.max_value >= max_cross.max_value){
            return max_right;
        }else{
            return max_cross;
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    max_entity max = find_max_sub_array(array, 0, 15);

    printf("%d\n", max.max_left_idx);
    printf("%d\n", max.max_right_idx);
    printf("%d\n", max.max_value);

    return 0;
}