//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scuola scuola = new Scuola();

        Classe classe1 = new Classe(2003, 4, "B");
        Classe classe2 = new Classe(2007, 1, "A");
        Classe classe3 = new Classe(2002, 5, "C");
        Classe classe4 = new Classe(2003, 4, "D");
        Classe classe5 = new Classe(2005, 2, "F");

        scuola.addClasse(classe1);
        scuola.addClasse(classe2);
        scuola.addClasse(classe3);
        scuola.addClasse(classe4);
        scuola.addClasse(classe5);


        System.out.println(classe1.getNome());




    }
}