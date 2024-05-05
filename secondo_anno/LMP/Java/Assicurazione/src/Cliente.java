public class Cliente {
    private String name;
    private String cognome;
    public Cliente(String name, String cognome) {
        this.name = name;
        this.cognome = cognome;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getCognome() {
        return cognome;
    }
    public void setCognome(String cognome) {
        this.cognome = cognome;
    }
    @Override
    public String toString() {
        return "Cliente [name=" + name + ", cognome=" + cognome + "]";
    }

    
    
}
