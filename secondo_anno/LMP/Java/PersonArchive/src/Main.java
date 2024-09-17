import java.time.LocalDate;

import services.Factory;

public class Main {
    public static void main(String[] args) {
        Factory factory = new Factory();

        factory.createPerson("Adriano", "Porzia", LocalDate.of(2003, 11, 23), "PRZDRN03S23H501I", 5, "Informatico");
        factory.createPerson("Pippo", "Porzia", LocalDate.of(2003, 11, 23), "PRZDRN03S23H501L", 5, "Informatico");

        factory.createPerson("Ionut", "Zbirciog", LocalDate.of(2002, 7, 11), "ZBRCGNT02SH929DJS", "Hacker", 5022);

        System.out.println(factory.getPerson("PRZDRN03S23H501I"));
        System.out.println(factory.getPerson("PRZDRN03S23H501L"));


        System.out.println("--------------------------");
            
    }
}
