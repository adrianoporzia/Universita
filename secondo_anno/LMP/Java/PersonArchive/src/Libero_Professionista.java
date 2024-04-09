import java.util.Date;

public class Libero_Professionista extends Person{
    private String professione;
    private String partitaIva;

    public Libero_Professionista(String nome, String cognome, Date dataDiNascita, String codiceFiscale, String professione, String partitaIva) {
        super(nome, cognome, dataDiNascita, codiceFiscale);
        this.professione = professione;
        this.partitaIva = partitaIva;
    }

    public String getProfessione() {
        return professione;
    }

    public void setProfessione(String professione) {
        this.professione = professione;
    }

    public String getPartitaIva() {
        return partitaIva;
    }

    public void setPartitaIva(String partitaIva) {
        this.partitaIva = partitaIva;
    }
}
