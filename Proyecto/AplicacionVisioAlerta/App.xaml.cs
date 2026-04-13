namespace AplicacionVisioAlerta;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        var tabbedPage = new TabbedPage();

        // Agregamos las pestañas (asegúrate de que los nombres coincidan con tus archivos en Views)
        tabbedPage.Children.Add(new NavigationPage(new Views.EstadoPage()) { Title = "Estado", IconImageSource = "estado_icon.png" });
        tabbedPage.Children.Add(new NavigationPage(new Views.AjustesPage()) { Title = "Ajustes", IconImageSource = "ajustes_icon.png" });

        MainPage = tabbedPage;
    }
}