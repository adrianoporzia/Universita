package models;

public class Componente {
    private String luogoProvenienza;
    private String nomeComponente;
    private int giorniOrdinazioneComponenti;
    private int costoComponente;
    private boolean privato; //se 1 privato, se 0 pubblico

    public Componente(String luogoProvenienza, String nomeComponente, int giorniOrdinazioneComponenti,
            int costoComponente, boolean privato) {
        this.luogoProvenienza = luogoProvenienza;
        this.nomeComponente = nomeComponente;
        this.giorniOrdinazioneComponenti = giorniOrdinazioneComponenti;
        this.costoComponente = costoComponente;
        this.privato = privato;
    }

    public String getLuogoProvenienza() {
        return luogoProvenienza;
    }

    public void setLuogoProvenienza(String luogoProvenienza) {
        this.luogoProvenienza = luogoProvenienza;
    }

    public String getNomeComponente() {
        return nomeComponente;
    }

    public void setNomeComponente(String nomeComponente) {
        this.nomeComponente = nomeComponente;
    }

    public int getGiorniOrdinazioneComponenti() {
        return giorniOrdinazioneComponenti;
    }

    public void setGiorniOrdinazioneComponenti(int giorniOrdinazioneComponenti) {
        this.giorniOrdinazioneComponenti = giorniOrdinazioneComponenti;
    }

    public int getCostoComponente() {
        return costoComponente;
    }

    public void setCostoComponente(int costoComponente) {
        this.costoComponente = costoComponente;
    }

    public boolean isPrivato() {
        return privato;
    }

    public void setPrivato(boolean privato) {
        this.privato = privato;
    }
    
    
    
}
