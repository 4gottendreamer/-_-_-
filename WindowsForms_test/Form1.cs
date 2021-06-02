using System;
using System.Drawing;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms_test
{
	public partial class Form1 : Form
	{
		readonly Random formRandom = new Random();
		int moveCount = 0,
			maxMoveCount = 10;

		public Form1()
		{
			InitializeComponent();
		}

		private async void Form1_Load( object sender, EventArgs e )
		{
			int delay = 10;
			async void ColorWaves()
			{
				for (byte red = this.BackColor.R,
					green = this.BackColor.G,
					blue = BackColor.B;
					red <= 255 && green <= 255 && blue <= 255;
					red++, green++, blue++, await Task.Delay(delay)
					) {
					this.BackColor = Color.FromArgb(red, green, blue);
					textBoxCount.Text =
						$"({BackColor.R};" +
						$" {BackColor.G};" +
						$" {BackColor.B})";
				}
				for (byte red = this.BackColor.R,
					green = this.BackColor.G,
					blue = BackColor.B;
					red > 0 && green > 0 && blue > 0;
					red--, green--, blue--, await Task.Delay(delay)
					) {
					this.BackColor = Color.FromArgb(red, green, blue);
					textBoxCount.Text =
						$"({BackColor.R};" +
						$" {BackColor.G};" +
						$" {BackColor.B})";
				}
			}
			Opacity = 0;
			for (int i = 0; Opacity < 1; Opacity += .05, i++) {
				await Task.Delay(5);
				labelHint.Text = i.ToString();
			}
			//ColorWaves();
		}

		async private void ButtonClose_Click( object sender, EventArgs e )
		{
			if (
				MessageBox.Show("Уже сдаёшься?", "Позорная капитуляция",
				MessageBoxButtons.YesNo, MessageBoxIcon.Warning)
				== DialogResult.Yes
				) {
				for (; Opacity > 0; Opacity -= .05) {
					await Task.Delay(5);
				}
				this.Close();
			}
		}

		private void ButtonClose_RandomMove()
		{
			this.buttonClose.Location = new System.Drawing.Point(
				formRandom.Next(0, ClientSize.Width - buttonClose.Size.Width),
				formRandom.Next(labelHint.Size.Height, ClientSize.Height - buttonClose.Size.Height)
				);
		}
		private void ApproximateBlackColor()
		{
			Color c = this.ForeColor;

			if (c.R == 0) {
				this.ForeColor = Color.FromArgb(1, c.G, c.B);
			}
			if (c.G == 0) {
				this.ForeColor = Color.FromArgb(c.R, 1, c.B);
			}
			if (c.B == 0) {
				this.ForeColor = Color.FromArgb(c.R, c.G, 1);
			}
		}
		private async void LabelColors_ChangeColorTo(
			int toRed, int toGreen, int toBlue, int delay = 0 )
		{
			Color c = labelColors.ForeColor;
			int devisor = 50;

			int dr = ((int)toRed - c.R)/devisor;
			dr = (dr == 0 ? (c.R < toRed ? 1 : -1) : dr);
			int dg =((int)toGreen - c.G)/devisor;
			dg = (dg == 0 ? (c.G < toGreen ? 1 : -1) : dg);
			int db =((int)toBlue - c.B)/devisor;
			db = (db == 0 ? (c.B < toBlue ? 1 : -1) : db);

			for (int r = c.R, g = c.G, b = c.B;
				r < toRed && g < toGreen && b < toBlue;
				r += dr, g += dg, b += db,
				//r++, g++, b++,
				await Task.Delay(delay)) {
				labelColors.ForeColor = Color.FromArgb(r, g, b);
				labelHint.Text =
					$"({labelColors.ForeColor.R};" +
					$" {labelColors.ForeColor.G};" +
					$" {labelColors.ForeColor.B})";
			}

			labelColors.ForeColor = Color.FromArgb(toRed, toGreen, toBlue);
			labelHint.Text =
				$"({labelColors.ForeColor.R};" +
				$" {labelColors.ForeColor.G};" +
				$" {labelColors.ForeColor.B})";
			textBoxCount.Text = "DONE";
		}
		private async void LabelColor_ChangeColorRTo( int toRed, int delay )
		{
			Color c = labelColors.ForeColor;
			int devisor = 20;

			int dr = ((int)toRed - c.R)/devisor;
			dr = (dr == 0 ? (c.R < toRed ? 1 : -1) : dr);

			for (int r = c.R, g = c.G, b = c.B;
				r < toRed;
				r += dr, await Task.Delay(delay)) {
				labelColors.ForeColor = Color.FromArgb(r, g, b);
				labelHint.Text =
					$"({labelColors.ForeColor.R};" +
					$" {labelColors.ForeColor.G};" +
					$" {labelColors.ForeColor.B})";
			}
		}
		private async void LabelColor_ChangeColorGTo( int toGreen, int delay )
		{
			Color c = labelColors.ForeColor;
			int devisor = 20;

			int dg = ((int)toGreen - c.G)/devisor;
			dg = (dg == 0 ? (c.G < toGreen ? 1 : -1) : dg);

			for (int r = c.G, g = c.G, b = c.B;
				g < toGreen;
				g += dg, await Task.Delay(delay)) {
				labelColors.ForeColor = Color.FromArgb(r, g, b);
				labelHint.Text =
					$"({labelColors.ForeColor.R};" +
					$" {labelColors.ForeColor.G};" +
					$" {labelColors.ForeColor.B})";
			}
		}
		private async void LabelColor_ChangeColorBTo( int toBlue, int delay )
		{
			Color c = labelColors.ForeColor;
			int devisor = 20;

			int db = ((int)toBlue - c.B)/devisor;
			db = (db == 0 ? (c.B < toBlue ? 1 : -1) : db);

			for (int r = c.B, g = c.G, b = c.B;
				b < toBlue;
				b += db, await Task.Delay(delay)) {
				labelColors.ForeColor = Color.FromArgb(r, g, b);
				labelHint.Text =
					$"({labelColors.ForeColor.R};" +
					$" {labelColors.ForeColor.G};" +
					$" {labelColors.ForeColor.B})";
			}
		}
		private void ButtonColor_Click( object sender, EventArgs e )
		{
			textBoxCount.Text = "";
			Random randomByte = new Random();
			//LabelColors_ChangeColorTo(255, 255, 255, 1);
			LabelColors_ChangeColorTo(
				randomByte.Next(0, 255),
				randomByte.Next(0, 255),
				randomByte.Next(0, 255), 100
				//randomByte.Next(10, 100)
				);
			//LabelColor_ChangeColorRTo(randomByte.Next(0, 255), randomByte.Next(10,100));
			//LabelColor_ChangeColorGTo(randomByte.Next(0, 255), randomByte.Next(10,100));
			//LabelColor_ChangeColorBTo(randomByte.Next(0, 255), randomByte.Next(10,100));
			labelDone.Text =
				$"({labelColors.ForeColor.R};" +
				$" {labelColors.ForeColor.G};" +
				$" {labelColors.ForeColor.B})";
		}

		private void TrackBar1_Scroll( object sender, EventArgs e )
		{
			Random random = new Random();
			//BackColor = Color.FromArgb((byte)trackBar1.Value, (byte)trackBar1.Value, (byte)trackBar1.Value);
			BackColor = Color.FromArgb(
				(byte)(BackColor.R + random.Next(0, 5)),
				(byte)(BackColor.G + random.Next(0, 5)),
				(byte)(BackColor.B + random.Next(0, 5))
				);
		}

		private void Form1_MouseMove( object sender, MouseEventArgs e )
		{
			Random random = new Random();
			BackColor = Color.FromArgb(
				(byte)(BackColor.R + random.Next(0, 2)),
				(byte)(BackColor.G + random.Next(0, 2)),
				(byte)(BackColor.B + random.Next(0, 2))
				);
		}

		private void buttonText_Click( object sender, EventArgs e )
		{
			string filePath = @"10500_symbols.txt";
			for (int i = 0; i < 10500; i++) {
				System.IO.File.AppendAllText(filePath, "c");
			}
		}

		private void ButtonClose_MouseMove( object sender, MouseEventArgs e )
		{
			ButtonClose_RandomMove();
			/*if (moveCount < maxMoveCount) {
				moveCount++;
			}
			else {
				labelHint.Text = "Нажатие пробела или Enter активирует кнопку";
				moveCount++;
			}
			this.textBoxCount.Text = $"0b{Convert.ToString(moveCount, 2)}";*/

		}
	}
}
