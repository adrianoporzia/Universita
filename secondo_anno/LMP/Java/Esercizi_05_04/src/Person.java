import java.util.Date;

public class Person {
    private String nome;
    private String cognome;
    private Date data;
    private String codiceFiscale;

    public Person(String nome, String cognome, Date data, String codiceFiscale) {
        this.nome = nome;
        this.cognome = cognome;
        this.data = data;
        this.codiceFiscale = codiceFiscale;
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

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }
}
