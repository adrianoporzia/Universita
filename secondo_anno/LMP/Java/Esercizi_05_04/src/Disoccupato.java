import java.util.Date;

public class Disoccupato extends Person{
    private String iscrizioneRegistroDisoccupati;
    public Disoccupato(String nome, String cognome, Date data, String codiceFiscale, String iscrizioneRegistroDisoccupati) {
        super(nome, cognome, data, codiceFiscale);
        this.iscrizioneRegistroDisoccupati = iscrizioneRegistroDisoccupati;
    }

    public String getIscrizioneRegistroDisoccupati() {
        return iscrizioneRegistroDisoccupati;
    }

    public void setIscrizioneRegistroDisoccupati(String iscrizioneRegistroDisoccupati) {
        this.iscrizioneRegistroDisoccupati = iscrizioneRegistroDisoccupati;
    }
}
