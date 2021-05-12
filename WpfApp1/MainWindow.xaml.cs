using System.Windows;

namespace WpfApp1
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
			for (Opacity = 0; Opacity < 1.0; Opacity += 0.1) {

			}
		}

		private void Button_Click( object sender, RoutedEventArgs e )
		{
			Close();
		}
	}
}
