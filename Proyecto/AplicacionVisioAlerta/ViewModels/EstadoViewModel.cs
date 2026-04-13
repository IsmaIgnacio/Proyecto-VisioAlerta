using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

namespace AplicacionVisioAlerta.ViewModels
{
    public class EstadoViewModel : INotifyPropertyChanged
    {
        private bool _sensoresActivos;
        private int _bateria = 85;

        public bool SensoresActivos
        {
            get => _sensoresActivos;
            set
            {
                _sensoresActivos = value;
                OnPropertyChanged();
                OnPropertyChanged(nameof(TextoBoton));
                OnPropertyChanged(nameof(ColorBoton));
            }
        }

        public int Bateria => _bateria;
        public string TextoBoton => SensoresActivos ? "Sensores Activos" : "Activar sensores";
        public Color ColorBoton => SensoresActivos ? Color.FromArgb("#FF5252") : Color.FromArgb("#2ECC71");

        public ICommand AlternarSensoresCommand { get; }

        public EstadoViewModel()
        {
            AlternarSensoresCommand = new Command(() => SensoresActivos = !SensoresActivos);
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged([CallerMemberName] string name = null) =>
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}