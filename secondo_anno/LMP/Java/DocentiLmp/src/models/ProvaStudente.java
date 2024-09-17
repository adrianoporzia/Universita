package models;

public class ProvaStudente {
    private String nomeStudente;
    private String cognomeStudente;
    private int matricola;
    private int votoScrittoJava;
    private int votoScrittoProlog;
    private int votoScrittoPython; 
    private int votoOraleJava;
    private int votoOraleProlog;
    private int bonus;
    private String argomentiJava;
    private String argomentiProlog;
    private String argomentiPython; 

    public ProvaStudente(String nomeStudente, String cognomeStudente, int matricola, 
            int votoScrittoJava, int votoScrittoProlog, int votoScrittoPython, int votoOraleJava, int votoOraleProlog, int bonus,
            String argomentiJava, String argomentiProlog, String argomentiPython) {
        this.nomeStudente = nomeStudente;
        this.cognomeStudente = cognomeStudente;
        this.matricola = matricola;
        this.votoScrittoJava = votoScrittoJava;
        this.votoScrittoProlog = votoScrittoProlog;
        this.votoScrittoPython = votoScrittoPython;
        this.votoOraleJava = votoOraleJava;
        this.votoOraleProlog = votoOraleProlog;
        this.bonus = bonus;
        this.argomentiJava = argomentiJava;
        this.argomentiProlog = argomentiProlog;
        this.argomentiPython = argomentiPython;
    }

    public String getNomeStudente() {
        return nomeStudente;
    }

    public void setNomeStudente(String nomeStudente) {
        this.nomeStudente = nomeStudente;
    }

    public String getCognomeStudente() {
        return cognomeStudente;
    }

    public void setCognomeStudente(String cognomeStudente) {
        this.cognomeStudente = cognomeStudente;
    }

    public int getMatricola() {
        return matricola;
    }

    public void setMatricola(int matricola) {
        this.matricola = matricola;
    }

    
    public int getVotoScrittoJava() {
        return votoScrittoJava;
    }

    public void setVotoScrittoJava(int votoScrittoJava) {
        if(votoScrittoJava > 30){
            throw new IllegalArgumentException("Voto non valido");
        }
        this.votoScrittoJava = votoScrittoJava;
    }

    public int getVotoScrittoProlog() {
        return votoScrittoProlog;
    }

    public void setVotoScrittoProlog(int votoScrittoProlog) {
        if(votoScrittoJava > 30){
            throw new IllegalArgumentException("Voto non valido");
        }
        this.votoScrittoProlog = votoScrittoProlog;
    }

    public int getVotoScrittoPython() {
        return votoScrittoPython;
    }

    public void setVotoScrittoPython(int votoScrittoPython) {
        if(votoScrittoJava > 30){
            throw new IllegalArgumentException("Voto non valido");
        }
        this.votoScrittoPython = votoScrittoPython;
    }

    public int getVotoOraleJava() {
        return votoOraleJava;
    }

    public void setVotoOraleJava(int votoOraleJava) {
        if(votoScrittoJava > 30){
            throw new IllegalArgumentException("Voto non valido");
        }
        this.votoOraleJava = votoOraleJava;
    }

    public int getVotoOraleProlog() {
        return votoOraleProlog;
    }

    public void setVotoOraleProlog(int votoOraleProlog) {
        if(votoScrittoJava > 30){
            throw new IllegalArgumentException("Voto non valido");
        }
        this.votoOraleProlog = votoOraleProlog;
    }

    public int getBonus() {
        return bonus;
    }

    public void setBonus(int bonus) {
        this.bonus = bonus;
    }

    public String getArgomentiJava() {
        return argomentiJava;
    }

    public void setArgomentiJava(String argomentiJava) {
        this.argomentiJava = argomentiJava;
    }

    public String getArgomentiProlog() {
        return argomentiProlog;
    }

    public void setArgomentiProlog(String argomentiProlog) {
        this.argomentiProlog = argomentiProlog;
    }

    public String getArgomentiPyhton() {
        return argomentiPython;
    }

    public void setArgomentiPyhton(String argomentiPyhton) {
        this.argomentiPython = argomentiPyhton;
    }


    public int getMediaVotiScritti(){
        int java = getVotoScrittoJava();
        int prolog = getVotoScrittoProlog();
        int python = getVotoScrittoPython();
        int somma = java + prolog + python;
        return somma / 3;

    }

    public int getMediaVotiOrali(){
        int java = getVotoOraleJava();
        int prolog = getVotoOraleProlog();
        int somma = java + prolog;
        return somma / 2;

    }

    public int getVotoFinale(){
        int mediaOrali = getMediaVotiOrali();
        int mediaScritti = getMediaVotiScritti();
        int mediaTotale = (mediaOrali + mediaScritti) / 2;
        return (mediaTotale + getBonus());
    }

    public boolean isPromosso(){
        if(getVotoFinale() >= 18){
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "ProvaStudente [nomeStudente=" + nomeStudente + ", cognomeStudente=" + cognomeStudente + ", matricola="
                + matricola + ", votoScrittoJava=" + votoScrittoJava + ", votoScrittoProlog="
                + votoScrittoProlog + ", votoScrittoPython=" + votoScrittoPython + ", votoOraleJava=" + votoOraleJava
                + ", votoOraleProlog=" + votoOraleProlog + ", bonus=" + bonus + ", argomentiJava=" + argomentiJava
                + ", argomentiProlog=" + argomentiProlog + ", argomentiPyhton=" + argomentiPython + "]";
    }

    
    
    
}
