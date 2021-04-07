
namespace WindowsForms_test
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose( bool disposing )
		{
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.buttonClose = new System.Windows.Forms.Button();
			this.labelHint = new System.Windows.Forms.Label();
			this.textBoxCount = new System.Windows.Forms.TextBox();
			this.labelColors = new System.Windows.Forms.Label();
			this.buttonColor = new System.Windows.Forms.Button();
			this.labelDone = new System.Windows.Forms.Label();
			this.trackBar1 = new System.Windows.Forms.TrackBar();
			this.buttonText = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
			this.SuspendLayout();
			// 
			// buttonClose
			// 
			this.buttonClose.AutoSize = true;
			this.buttonClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
			this.buttonClose.Location = new System.Drawing.Point(109, 88);
			this.buttonClose.Name = "buttonClose";
			this.buttonClose.Size = new System.Drawing.Size(87, 25);
			this.buttonClose.TabIndex = 0;
			this.buttonClose.Text = "Закрой меня";
			this.buttonClose.UseVisualStyleBackColor = false;
			this.buttonClose.Click += new System.EventHandler(this.ButtonClose_Click);
			this.buttonClose.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ButtonClose_MouseMove);
			// 
			// labelHint
			// 
			this.labelHint.AutoSize = true;
			this.labelHint.Location = new System.Drawing.Point(12, 12);
			this.labelHint.Margin = new System.Windows.Forms.Padding(3);
			this.labelHint.Name = "labelHint";
			this.labelHint.Size = new System.Drawing.Size(48, 13);
			this.labelHint.TabIndex = 1;
			this.labelHint.Text = "labelHint";
			// 
			// textBoxCount
			// 
			this.textBoxCount.Location = new System.Drawing.Point(192, 12);
			this.textBoxCount.Name = "textBoxCount";
			this.textBoxCount.Size = new System.Drawing.Size(100, 20);
			this.textBoxCount.TabIndex = 2;
			this.textBoxCount.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
			// 
			// labelColors
			// 
			this.labelColors.AutoSize = true;
			this.labelColors.Font = new System.Drawing.Font("Lucida Console", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.labelColors.Location = new System.Drawing.Point(95, 134);
			this.labelColors.Name = "labelColors";
			this.labelColors.Size = new System.Drawing.Size(114, 21);
			this.labelColors.TabIndex = 3;
			this.labelColors.Text = "Colorful";
			this.labelColors.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// buttonColor
			// 
			this.buttonColor.Location = new System.Drawing.Point(115, 166);
			this.buttonColor.Name = "buttonColor";
			this.buttonColor.Size = new System.Drawing.Size(75, 23);
			this.buttonColor.TabIndex = 4;
			this.buttonColor.Text = "Color";
			this.buttonColor.UseVisualStyleBackColor = true;
			this.buttonColor.Click += new System.EventHandler(this.ButtonColor_Click);
			// 
			// labelDone
			// 
			this.labelDone.AutoSize = true;
			this.labelDone.Location = new System.Drawing.Point(12, 28);
			this.labelDone.Name = "labelDone";
			this.labelDone.Size = new System.Drawing.Size(55, 13);
			this.labelDone.TabIndex = 5;
			this.labelDone.Text = "labelDone";
			// 
			// trackBar1
			// 
			this.trackBar1.Location = new System.Drawing.Point(247, 38);
			this.trackBar1.Maximum = 255;
			this.trackBar1.Name = "trackBar1";
			this.trackBar1.Orientation = System.Windows.Forms.Orientation.Vertical;
			this.trackBar1.Size = new System.Drawing.Size(45, 151);
			this.trackBar1.TabIndex = 1;
			this.trackBar1.TickFrequency = 10;
			this.trackBar1.TickStyle = System.Windows.Forms.TickStyle.Both;
			this.trackBar1.Value = 128;
			this.trackBar1.Scroll += new System.EventHandler(this.TrackBar1_Scroll);
			// 
			// buttonText
			// 
			this.buttonText.Location = new System.Drawing.Point(115, 59);
			this.buttonText.Name = "buttonText";
			this.buttonText.Size = new System.Drawing.Size(75, 23);
			this.buttonText.TabIndex = 6;
			this.buttonText.Text = "buttonText";
			this.buttonText.UseVisualStyleBackColor = true;
			this.buttonText.Click += new System.EventHandler(this.buttonText_Click);
			// 
			// Form1
			// 
			this.BackColor = System.Drawing.SystemColors.ControlDark;
			this.ClientSize = new System.Drawing.Size(304, 201);
			this.Controls.Add(this.buttonText);
			this.Controls.Add(this.trackBar1);
			this.Controls.Add(this.labelDone);
			this.Controls.Add(this.buttonColor);
			this.Controls.Add(this.labelColors);
			this.Controls.Add(this.textBoxCount);
			this.Controls.Add(this.labelHint);
			this.Controls.Add(this.buttonClose);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.Name = "Form1";
			this.Opacity = 0D;
			this.ShowIcon = false;
			this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Load += new System.EventHandler(this.Form1_Load);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
			((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button buttonClose;
		private System.Windows.Forms.Label labelHint;
		private System.Windows.Forms.TextBox textBoxCount;
		private System.Windows.Forms.Label labelColors;
		private System.Windows.Forms.Button buttonColor;
		private System.Windows.Forms.Label labelDone;
		private System.Windows.Forms.TrackBar trackBar1;
		private System.Windows.Forms.Button buttonText;
	}
}

