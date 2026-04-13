using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

namespace AplicacionVisioAlerta.ViewModels
{
    public class AjustesViewModel : INotifyPropertyChanged
    {
        private double _distancia = 50; // Valor inicial igual a tu Figma
        private bool _vibracionOk = true;

        public double Distancia
        {
            get => _distancia;
            set { _distancia = value; OnPropertyChanged(); }
        }

        public bool VibracionOk
        {
            get => _vibracionOk;
            set { _vibracionOk = value; OnPropertyChanged(); }
        }

        public ICommand GuardarCambiosCommand { get; }

        public AjustesViewModel()
        {
            GuardarCambiosCommand = new Command(async () => await GuardarEnESP32());
        }

        private async Task GuardarEnESP32()
        {
            // Aquí en la Actividad 3 pondremos el código Wi-Fi real
            // Por ahora, simulamos la acción para la Actividad 2
            await App.Current.MainPage.DisplayAlert("Éxito",
                $"Configuración enviada:\nDistancia: {Math.Round(Distancia)} cm\nVibración: {VibracionOk}",
                "OK");
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged([CallerMemberName] string name = null) =>
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}