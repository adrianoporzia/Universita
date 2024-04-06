import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Dipendente {
    private String nome;
    private String cognome;
    private Date dataDiNascita;
    private Date dataDiAssunzione;
    private static int nMatricola;
    private String matricola;
    private String dipartimento;
    private String mansione;
    private int livello;
    private int capo;

    public Dipendente(String nome, String cognome, String dataDiNascita, String dataDiAssunzione) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = parseStringToDate(dataDiNascita);
        this.dataDiAssunzione = parseStringToDate(dataDiAssunzione);
    }

    private Date parseStringToDate(String dateString) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return sdf.parse(dateString);
        } catch (ParseException e) {
            System.out.println("Errore nel parse");
            return null;
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public Date getDataDiNascita() {
        return dataDiNascita;
    }

    public void setDataDiNascita(Date dataDiNascita) {
        this.dataDiNascita = dataDiNascita;
    }

    public Date getDataDiAssunzione() {
        return dataDiAssunzione;
    }

    public void setDataDiAssunzione(Date dataDiAssunzione) {
        this.dataDiAssunzione = dataDiAssunzione;
    }

    public void createDipendente(String nome, String cognome, )
}
