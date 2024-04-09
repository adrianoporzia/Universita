import java.util.Date;

public class Disoccupato extends Person{
    private String registroDisoccupati;

    public Disoccupato(String nome, String cognome, Date dataDiNascita, String codiceFiscale, String registroDisoccupati) {
        super(nome, cognome, dataDiNascita, codiceFiscale);
        this.registroDisoccupati = registroDisoccupati;
    }

    public String getRegistroDisoccupati() {
        return registroDisoccupati;
    }

    public void setRegistroDisoccupati(String registroDisoccupati) {
        this.registroDisoccupati = registroDisoccupati;
    }
}
