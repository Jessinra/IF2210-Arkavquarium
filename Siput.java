import java.util.*;

public class Siput extends Pet {
    private double distance_to_coin;
    private int speed;

    public Siput() {
        distance_to_coin = 0;
        set_speed(SIPUT_MOVEMENT_SPD);
        super.set_dir("Right");
        super.set_x(SCREEN_WIDTH/2);
        super.set_y(SCREEN_BOTTOM);
    }

    public int get_speed() {
        return this.speed;
    }

    public void set_speed(int speed) {
        this.speed = speed;
    }

    public void draw() {
        if (super.get_dir() == "Left") {
            super.draw_image(FILE_siput_left, super.get_x(), super.get_y());
        } else {
            super.draw_image(FILE_siput_right, super.get_x(), super.get_y());
        }
    }

    public void move(double sec_since_last, LinkedList<Coin> C) {
        int x_coin;

        if (C.getNBelmt() > 0) {
            int radius = inRadius(C);

            System.out.println("Siput move " + super.get_x() + "," + super.get_y());
            x_coin = C.get(radius).get_x();
            if (abs(x_coin - super.get_x()) > 30) {
                if (x_coin - super.get_x() > 0) {
                    super.set_x(super.get_x() + sec_since_last*super.get_speed());
                    super.set_dir("Right");
                } else {
                    super.set_x(super.get_x() - sec_since_last*super.get_speed());
                    super.set_dir("Left");
                }
            }
        }
    }

    public double euclidean() {}

    public boolean find_coin(LinkedList<Coin> C) {
        boolean find = false;
        int i = 1;

        while (i < C.getNBelmt() && !find) {
            if (C.get(i).get_y() == Constant.SCREEN_BOTTOM) {
                find = true;
            } else {
                i++;
            }
        }
        return find;
    }

    public int inRadius(LinkedList<Coin> C) {
        int idx = 1;
        int nearest;
        double radius = 1;
        boolean find = false;

        if (find_coin(C)) {
            for (idx=1; idx<=C.getNBelmt(); idx++) {
                if (C.get(idx).get_y() == Constant.SCREEN_BOTTOM) {
                    break;
                }
            }
            nearest = abs(C.get(idx).get_x() - super.get_x());
            while (idx+1 < C.getNBelmt()) {
                if (C.get(idx).get_y() == Constant.SCREEN_BOTTOM) {
                    if (abs(C.get(idx).get_x() - super.get_x()) < nearest) {
                        nearest = abs(C.get(idx).get_x() - super.get_x());
                        radius = idx;
                    } else {
                        idx++;
                    }
                } else {
                    idx++;
                }
            }
        } else {
            nearest = C.get(idx).get_y();
            for (idx=2; idx<=C.getNBelmt(); idx++) {
                if (C.get(idx).get_y() > nearest) {
                    radius = idx;
                }
            }
        }
        return radius;
    }

    public int take_coin() {
        if (C.getNBelmt() > 0) {
            int idx = inRadius(C);
            if (C.get(idx).get_x() >= super.get_x() - 30 && C.get(idx).get_x() + 30 && C.get(idx).get_y() == Constant.SCREEN_BOTTOM) {
                int value = C.get(idx).get_value();
                C.remove(C.get(idx));
                return value;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
}
