// Write your Checker class here
import java.util.Comparator;

class Checker implements Comparator<Player> {

    @Override
    public int compare(Player x, Player y){
      if (y.score != x.score) return y.score - x.score;
      else return x.name.compareTo(y.name);
    }
}
