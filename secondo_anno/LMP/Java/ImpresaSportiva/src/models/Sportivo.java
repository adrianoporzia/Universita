    package models;

    import java.time.LocalDate;
    import java.util.HashMap;

    public class Sportivo{
        private String nome;
        private String cognome;
        private HashMap<Integer, Integer> golSportivo;
        private LocalDate dataDiAssunzione;
        private static int count = 1;
        private TipoSportivo tipologiaSportivo;
        private String numeroIscrizione;
        private int livelloStipendiale;

        public Sportivo(String nome, String cognome, LocalDate dataDiAssunzione,
                TipoSportivo tipologiaSportivo, int livelloStipendiale) {
            this.nome = nome;
            this.cognome = cognome;
            this.golSportivo = new HashMap<>();
            this.dataDiAssunzione = dataDiAssunzione;
            this.tipologiaSportivo = tipologiaSportivo;
            this.numeroIscrizione = "TEAM_" + count++;
            this.setLivelloStipendiale(livelloStipendiale);
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

        public HashMap<Integer, Integer> getGolSportivo() {
            return golSportivo;
        }

        
        public LocalDate getDataDiAssunzione() {
            return dataDiAssunzione;
        }

        public void setDataDiAssunzione(LocalDate dataDiAssunzione) {
            this.dataDiAssunzione = dataDiAssunzione;
        }

        public TipoSportivo getTipologiaSportivo() {
            return tipologiaSportivo;
        }

        public void setTipologiaSportivo(TipoSportivo tipologiaSportivo) {
            this.tipologiaSportivo = tipologiaSportivo;
        }

        public String getNumeroIscrizione() {
            return numeroIscrizione;
        }

        public void setNumeroIscrizione(String numeroIscrizione) {
            this.numeroIscrizione = numeroIscrizione;
        }

        public int getLivelloStipendiale() {
            return livelloStipendiale;
        }

        public void setLivelloStipendiale(int livelloStipendiale) {
            if(livelloStipendiale < 1 || livelloStipendiale > 5){
                throw new IllegalArgumentException("Livello stipendiale non valido");
            }
            this.livelloStipendiale = livelloStipendiale;
        }

        public void setGolPerMese(int mese, int nuoviGol){
            if(!golSportivo.containsKey(mese)){
                golSportivo.put(mese, 0);
            }
            int golVecchi = golSportivo.get(mese);
            int golFinali = golVecchi + nuoviGol;
            golSportivo.put(mese, golFinali); 
            }

        public int getGolPerMese(int mese){
            if(!golSportivo.containsKey(mese)){
                golSportivo.put(mese, 0);
                return 0;
            }
            return golSportivo.get(mese);
        }

        @Override
        public String toString() {
            return "Sportivo [nome=" + nome + ", cognome=" + cognome + "]";
        }

        
        

        

    }
