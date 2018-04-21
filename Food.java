import java.util.*;

public class Food extends Object implements Moveable {
    private static int food_count = 0;
    private int food_id;
    private int food_speed;

    public Food() {
        super.set_y(Constant.SCREEN_TOP);
        Random rand = new Random();
        int a = rand.nextInt() % Constant.SCREEN_WIDTH + 1;
        super.set_x((double) a);
        food_count += 1;
        set_id(food_count);
        set_speed(Constant.FOOD_MOVEMENT_SPD);
    }
    public Food(double x) {
        super.set_y(SCREEN_TOP);
        super.set_x(x);
        food_count += 1;
        set_id(food_count);
        set_speed(Constant.FOOD_MOVEMENT_SPD);
    }
    public int get_id() {
        return food_id;
    }
    public void set_id(int id) {
        this.food_id = id;
    }
    public int get_speed() {
        return food_speed;
    }
    public void set_speed(int spd) {
        this.food_speed = spd;
    }
    public void draw() {
        draw_image(Constant.FILE_food, super.get_x(), super.get_y());
    }
    public void move() {
        super(sec_since_last);
        if (super.get_y() <= Constant.SCREEN_BOTTOM) {
            System.out.println("Food move " + super.get_x() + "," + super.get_y());
            super.set_y(super.get_y() + (super.get_speed() * sec_since_last))
        }
    }
}
