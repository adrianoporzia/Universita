import java.util.Calendar;

public class Main {
    public static void main(String[] args) throws Exception {

        Legge legge1 = new Legge("Tipo1", new Date(Calendar.getInstance().getTimeInMillis()), "Testo legge 1");
        aggiungiLegge(legge1);

        Legge legge2 = new Legge("Tipo2", new Date(Calendar.getInstance().getTimeInMillis()), "Testo legge 2");
        aggiungiLegge(legge2);
    }
}
