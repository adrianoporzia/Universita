import java.time.LocalDate;
import models.ProvaStudente;
import services.Esame;

public class Main {
    public static void main(String[] args) {
        Esame esame = new Esame(LocalDate.of(2023, 11, 7), 3);
       
        ProvaStudente provaAdriano = new ProvaStudente(
            "Adriano",    
            "Porzia",
            123456,       
            28,          
            25,
            30,          
            26,           
            27,          
            2,             
            "Interface",    
            "Grammatiche",   
            "Classi"        
        );

        // Prova di Maria
        ProvaStudente provaMaria = new ProvaStudente(
            "Maria",   
            "Rossi",       
            654321,      
            30,          
            28,              
            29,          
            25,             
            24,           
            1,            
            "Polimorfismo", 
            "Ricorsione",  
            "Ereditarietà"  
        );

        // Prova di Giovanni
        ProvaStudente provaGiovanni = new ProvaStudente(
            "Giovanni",     
            "Bianchi",   
            789012,  
            27,  
            26,      
            28,      
            29,             
            30,              
            3,              
            "Lambda",    
            "Unificazione",
            "Stream"         
        );

       
        esame.addProve(provaAdriano);
        esame.addProve(provaMaria);
        esame.addProve(provaGiovanni);
        
    }
}
