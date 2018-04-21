import java.util.*;

public class Pet extends Object implements Moveable {
    private pet_count = 0;
    private pet_id = pet_count;

    public Pet() {
        pet_count++;
        pet_id = pet_count++;
    }
    public int get_id() { return pet_id; }
}
