import java.util.Date;

public class Studente {

    private Date dataDiNascita;
    private String luogoDiNascita;
    private String nome;
    private String cognome;
    private int annoDiIscrizione;
    private int anniRipetenza;

    public Studente(Date dataDiNascita, String luogoDiNascita, String nome, String cognome, int annoDiIscrizione, int anniRipetenza) {
        this.dataDiNascita = dataDiNascita;
        this.luogoDiNascita = luogoDiNascita;
        this.nome = nome;
        this.cognome = cognome;
        this.annoDiIscrizione = annoDiIscrizione;
        this.anniRipetenza = 0;
    }

    public Date getDataDiNascita() {
        return dataDiNascita;
    }

    public void setDataDiNascita(Date dataDiNascita) {
        this.dataDiNascita = dataDiNascita;
    }

    public String getLuogoDiNascita() {
        return luogoDiNascita;
    }

    public void setLuogoDiNascita(String luogoDiNascita) {
        this.luogoDiNascita = luogoDiNascita;
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

    public int getAnnoDiIscrizione() {
        return annoDiIscrizione;
    }

    public void setAnnoDiIscrizione(int annoDiIscrizione) {
        this.annoDiIscrizione = annoDiIscrizione;
    }

    public int getAnniRipetenza() {
        return anniRipetenza;
    }

    public void setAnniRipetenza(int anniRipetenza) {
        this.anniRipetenza = anniRipetenza;
    }
}
