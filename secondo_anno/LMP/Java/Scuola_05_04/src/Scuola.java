import java.util.HashMap;

public class Scuola {
    private HashMap<String, Classe> classi;

    public Scuola() {
        this.classi = new HashMap<>();
    }

    public void addClasse(Classe c){
        String nomeClasse = c.getNome();
        classi.put(nomeClasse, c);
    }

    public HashMap<String, Classe> getClassi() {
        return classi;
    }

    public void setClassi(HashMap<String, Classe> classi) {
        this.classi = classi;
    }


}
