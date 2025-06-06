package Task1;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{5, 4, 3, 2, 1};
        for (int j : arr) {
            System.out.print(j+",");
        }
        System.out.println();
        int smallestNumIndex;
        int tempNum;

        for (int i = 0; i < arr.length - 1; i++) {
            smallestNumIndex = i;

            for (int j = i + 1; j < arr.length; j++) {
                if(arr[j] < arr[smallestNumIndex]){
                    smallestNumIndex = j;
                }
            }

            if(smallestNumIndex != i){
                tempNum = arr[i];
                arr[i] = arr[smallestNumIndex];
                arr[smallestNumIndex] = tempNum;
            }
        }

        for (int j : arr) {
            System.out.print(j+",");
        }
    }
}
