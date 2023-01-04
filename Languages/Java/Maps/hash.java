package Maps;

import java.util.Map;
import java.lang.reflect.Array;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.LinkedHashMap;

public class hash {
    public static void main(String[] args) {

        int[] array = { 7, 6, 4, 10, 11, 1, 2, 3, 4, 5 };

        int target = 10;

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < array.length; i++) {
            map.put(array[i], i);
        }

        // for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        //     System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
        // }

        // if (map.get(11) == null) {
        //     System.out.println("not it");
        // }
        // else {
        //     System.out.println("it is: " + map.get(11));
        // }

      
        for (int i = 0; i < array.length; i++) {

            if (map.get(target - array[i]) != null) {
                System.out.printf("array[%d] + array[%d]", map.get(target - array[i]), i);
                System.out.print(": ");
                System.out.println(array[map.get(target - array[i])] + "+" + array[i]);
                System.out.println("\n");
            }

        }
    }
}
