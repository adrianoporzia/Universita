public class Automobile {
    private int targa;
    private Cliente proprietario;
    public Automobile(int targa, Cliente proprietario) {
        this.targa = targa;
        this.proprietario = proprietario;
    }
    public int getTarga() {
        return targa;
    }
    public void setTarga(int targa) {
        this.targa = targa;
    }
    public Cliente getProprietario() {
        return proprietario;
    }
    public void setProprietario(Cliente proprietario) {
        this.proprietario = proprietario;
    }
    @Override
    public String toString() {
        return "Automobile [targa=" + targa + ", proprietario=" + proprietario + "]";
    }
    
    
}
