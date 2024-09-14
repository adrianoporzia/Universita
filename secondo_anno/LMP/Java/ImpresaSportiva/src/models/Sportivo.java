package models;

import java.time.LocalDate;
import java.time.Month;
import java.util.HashMap;

public class Sportivo {
    private String nome;
    private String cognome;
    private HashMap<Month, Integer> retiSegnate;
    private LocalDate dataAssunzione;
    private int livelloStipendiale;
    private String numIscrizione;
    private static int count = 1;
    private TipoSportivo tipoSportivo;

    public Sportivo(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale, TipoSportivo tipoSportivo) {
        this.nome = nome;
        this.cognome = cognome;
        this.retiSegnate = new HashMap<>();
        this.setDataAssunzione(dataAssunzione);
        this.setLivelloStipendiale(livelloStipendiale);
        this.numIscrizione = generateNumIscrizione();  // Usa direttamente generateNumIscrizione()
        this.tipoSportivo = tipoSportivo;
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

    public void addReti(Month mese, int reti) {
        if(reti < 0){
            throw new IllegalArgumentException("Nessun goal da aggiornare");
        }
        int currReti = retiSegnate.getOrDefault(mese, 0);
        this.retiSegnate.put(mese, currReti + reti);
    }

    public LocalDate getDataAssunzione() {
        return dataAssunzione;
    }

    public void setDataAssunzione(LocalDate dataAssunzione) {
        if(dataAssunzione.getYear() < 2024){
            throw new IllegalArgumentException("La data non è compatibile");
        }
        this.dataAssunzione = dataAssunzione;
    }

    public int getLivelloStipendiale() {
        return livelloStipendiale;
    }

    public void setLivelloStipendiale(int livelloStipendiale) {
        if(livelloStipendiale < 1 || livelloStipendiale > 5){
            throw new IllegalArgumentException("Livello stipendiale incmpatibile.");
        }
        this.livelloStipendiale = livelloStipendiale;
    }

    // Genera il numero di iscrizione
    private String generateNumIscrizione() {
        return "TEAM_" + (count++);
    }

    public String getNumIscrizione() {
        return numIscrizione;
    }

    public void setNumIscrizione(String numIscrizione) {
        this.numIscrizione = numIscrizione;
    }

    public static int getCount() {
        return count;
    }

    public static void setCount(int count) {
        Sportivo.count = count;
    }

    public TipoSportivo getTipoSportivo() {
        return tipoSportivo;
    }

    public void setTipoSportivo(TipoSportivo tipoSportivo) {
        this.tipoSportivo = tipoSportivo;
    }

    @Override
    public String toString() {
        return "Sportivo [nome=" + nome + ", cognome=" + cognome + ", retiSegnate=" + retiSegnate + ", dataAssunzione="
                + dataAssunzione + ", livelloStipendiale=" + livelloStipendiale + ", numIscrizione=" + numIscrizione
                + ", tipoSportivo=" + tipoSportivo + "]";
    }

    public HashMap<Month, Integer> getRetiSegnate() {
        return retiSegnate;
    }
}
