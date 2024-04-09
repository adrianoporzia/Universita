import java.util.Date;

public class Dipendente {
    /*parametri di ogni singolo dipendente*/
    private String nome;
    private String cognome;
    private Date dataDiNascita;
    private Date dataDiAssunzione;
    /*parametri che vengono generati alla creazione*/
    private String matricola;
    private String dipartimento;
    private String mansione;
    private int livello;
    private String capo;

    /*static numero dipendenti*/
    private static int numeroDipendenti = 0;

    public Dipendente(String nome, String cognome, Date dataDiNascita, Date dataDiAssunzione, String matricola, String dipartimento, String mansione, int livello, String capo) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = dataDiNascita;
        this.dataDiAssunzione = dataDiAssunzione;
        this.matricola = matricola;
        this.dipartimento = dipartimento;
        this.mansione = mansione;
        this.livello = livello;
        this.capo = capo;
    }

    enum Dipartimento{
        marketing,
        risorseUmane,
        sviluppo
    }

    enum Mansione{
        fabbro,
        elettrcista,
        tecnico,
        falegname
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

    public String getMatricola() {
        return matricola;
    }

    public void setMatricola(String matricola) {
        this.matricola = matricola;
    }

    public String getDipartimento() {
        return dipartimento;
    }

    public void setDipartimento(String dipartimento) {
        this.dipartimento = dipartimento;
    }

    public String getMansione() {
        return mansione;
    }

    public void setMansione(String mansione) {
        this.mansione = mansione;
    }

    public int getLivello() {
        return livello;
    }

    public void setLivello(int livello) {
        this.livello = livello;
    }

    public String getCapo() {
        return capo;
    }

    public void setCapo(String capo) {
        this.capo = capo;
    }

    public static int getNumeroDipendenti() {
        return numeroDipendenti;
    }

    public static void setNumeroDipendenti(int numeroDipendenti) {
        Dipendente.numeroDipendenti = numeroDipendenti;
    }

    public void

}
