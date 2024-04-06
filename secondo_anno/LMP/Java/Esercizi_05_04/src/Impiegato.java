import java.util.Date;

public class Impiegato extends Person{

    private String matricola;
    private String livello;
    private String mansione;

    public Impiegato(String nome, String cognome, Date data, String codiceFiscale, String matricola, String livello, String mansione ) {
        super(nome, cognome, data, codiceFiscale);
        this.matricola = matricola;
        this.livello = livello;
        this.mansione = mansione;
    }

    public String getMatricola() {
        return matricola;
    }

    public void setMatricola(String matricola) {
        this.matricola = matricola;
    }

    public String getLivello() {
        return livello;
    }

    public void setLivello(String livello) {
        this.livello = livello;
    }

    public String getMansione() {
        return mansione;
    }

    public void setMansione(String mansione) {
        this.mansione = mansione;
    }
}