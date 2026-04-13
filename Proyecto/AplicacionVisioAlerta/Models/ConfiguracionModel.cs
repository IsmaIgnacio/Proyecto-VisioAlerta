namespace AplicacionVisioAlerta.Models
{
    public class ConfiguracionModel
    {
        public int NivelBateria { get; set; } = 85; // Mock data
        public bool SensoresActivos { get; set; } = false;
        public string EstadoConexion { get; set; } = "Conectado - Monitoreo remoto";
    }
}