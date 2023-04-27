using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            barraProgreso.Value = barraProgreso.Value + 10;
            if(barraProgreso.Value == 100)
            {
                MessageBox.Show("Carga Completada", "Aviso", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Application.Exit();
            }
            
        }

        
    }
}
