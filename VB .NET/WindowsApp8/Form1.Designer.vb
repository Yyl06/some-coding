<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.TabControl1 = New System.Windows.Forms.TabControl()
        Me.TabPage1 = New System.Windows.Forms.TabPage()
        Me.lblRentalResult = New System.Windows.Forms.Label()
        Me.btnCalculate = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.txtRentalDays = New System.Windows.Forms.TextBox()
        Me.lstRentalCars = New System.Windows.Forms.ListBox()
        Me.TabPage2 = New System.Windows.Forms.TabPage()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.btnCountCars = New System.Windows.Forms.Button()
        Me.btnDeleteCar = New System.Windows.Forms.Button()
        Me.btnAddCar = New System.Windows.Forms.Button()
        Me.txtNewCar = New System.Windows.Forms.TextBox()
        Me.lstManageCars = New System.Windows.Forms.ListBox()
        Me.TabPage3 = New System.Windows.Forms.TabPage()
        Me.btnGenerate = New System.Windows.Forms.Button()
        Me.lstNumbers = New System.Windows.Forms.ListBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.txtNum2 = New System.Windows.Forms.TextBox()
        Me.txtNum1 = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.txtNewPrice = New System.Windows.Forms.TextBox()
        Me.TabControl1.SuspendLayout()
        Me.TabPage1.SuspendLayout()
        Me.TabPage2.SuspendLayout()
        Me.TabPage3.SuspendLayout()
        Me.SuspendLayout()
        '
        'TabControl1
        '
        Me.TabControl1.Controls.Add(Me.TabPage1)
        Me.TabControl1.Controls.Add(Me.TabPage2)
        Me.TabControl1.Controls.Add(Me.TabPage3)
        Me.TabControl1.Location = New System.Drawing.Point(1, 2)
        Me.TabControl1.Name = "TabControl1"
        Me.TabControl1.SelectedIndex = 0
        Me.TabControl1.Size = New System.Drawing.Size(576, 353)
        Me.TabControl1.TabIndex = 0
        '
        'TabPage1
        '
        Me.TabPage1.Controls.Add(Me.lblRentalResult)
        Me.TabPage1.Controls.Add(Me.btnCalculate)
        Me.TabPage1.Controls.Add(Me.Label1)
        Me.TabPage1.Controls.Add(Me.txtRentalDays)
        Me.TabPage1.Controls.Add(Me.lstRentalCars)
        Me.TabPage1.Location = New System.Drawing.Point(4, 25)
        Me.TabPage1.Name = "TabPage1"
        Me.TabPage1.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage1.Size = New System.Drawing.Size(568, 324)
        Me.TabPage1.TabIndex = 0
        Me.TabPage1.Text = "Car Rental"
        Me.TabPage1.UseVisualStyleBackColor = True
        '
        'lblRentalResult
        '
        Me.lblRentalResult.AutoSize = True
        Me.lblRentalResult.Location = New System.Drawing.Point(224, 162)
        Me.lblRentalResult.Name = "lblRentalResult"
        Me.lblRentalResult.Size = New System.Drawing.Size(92, 16)
        Me.lblRentalResult.TabIndex = 4
        Me.lblRentalResult.Text = "Total Amount: "
        '
        'btnCalculate
        '
        Me.btnCalculate.Location = New System.Drawing.Point(241, 228)
        Me.btnCalculate.Name = "btnCalculate"
        Me.btnCalculate.Size = New System.Drawing.Size(90, 23)
        Me.btnCalculate.TabIndex = 3
        Me.btnCalculate.Text = "Calculate"
        Me.btnCalculate.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(240, 65)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(76, 16)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Rent Days: "
        '
        'txtRentalDays
        '
        Me.txtRentalDays.Location = New System.Drawing.Point(322, 62)
        Me.txtRentalDays.Name = "txtRentalDays"
        Me.txtRentalDays.Size = New System.Drawing.Size(100, 22)
        Me.txtRentalDays.TabIndex = 1
        '
        'lstRentalCars
        '
        Me.lstRentalCars.FormattingEnabled = True
        Me.lstRentalCars.ItemHeight = 16
        Me.lstRentalCars.Location = New System.Drawing.Point(73, 61)
        Me.lstRentalCars.Name = "lstRentalCars"
        Me.lstRentalCars.Size = New System.Drawing.Size(120, 84)
        Me.lstRentalCars.TabIndex = 0
        '
        'TabPage2
        '
        Me.TabPage2.Controls.Add(Me.Label5)
        Me.TabPage2.Controls.Add(Me.txtNewPrice)
        Me.TabPage2.Controls.Add(Me.Label2)
        Me.TabPage2.Controls.Add(Me.btnCountCars)
        Me.TabPage2.Controls.Add(Me.btnDeleteCar)
        Me.TabPage2.Controls.Add(Me.btnAddCar)
        Me.TabPage2.Controls.Add(Me.txtNewCar)
        Me.TabPage2.Controls.Add(Me.lstManageCars)
        Me.TabPage2.Location = New System.Drawing.Point(4, 25)
        Me.TabPage2.Name = "TabPage2"
        Me.TabPage2.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage2.Size = New System.Drawing.Size(568, 324)
        Me.TabPage2.TabIndex = 1
        Me.TabPage2.Text = "Car Management"
        Me.TabPage2.UseVisualStyleBackColor = True
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(197, 46)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(108, 16)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Enter Car Name: "
        '
        'btnCountCars
        '
        Me.btnCountCars.Location = New System.Drawing.Point(292, 195)
        Me.btnCountCars.Name = "btnCountCars"
        Me.btnCountCars.Size = New System.Drawing.Size(92, 23)
        Me.btnCountCars.TabIndex = 5
        Me.btnCountCars.Text = "Total Cars"
        Me.btnCountCars.UseVisualStyleBackColor = True
        '
        'btnDeleteCar
        '
        Me.btnDeleteCar.Location = New System.Drawing.Point(183, 195)
        Me.btnDeleteCar.Name = "btnDeleteCar"
        Me.btnDeleteCar.Size = New System.Drawing.Size(89, 23)
        Me.btnDeleteCar.TabIndex = 4
        Me.btnDeleteCar.Text = "Delete Car"
        Me.btnDeleteCar.UseVisualStyleBackColor = True
        '
        'btnAddCar
        '
        Me.btnAddCar.Location = New System.Drawing.Point(81, 195)
        Me.btnAddCar.Name = "btnAddCar"
        Me.btnAddCar.Size = New System.Drawing.Size(75, 23)
        Me.btnAddCar.TabIndex = 3
        Me.btnAddCar.Text = "Add Car"
        Me.btnAddCar.UseVisualStyleBackColor = True
        '
        'txtNewCar
        '
        Me.txtNewCar.Location = New System.Drawing.Point(311, 43)
        Me.txtNewCar.Name = "txtNewCar"
        Me.txtNewCar.Size = New System.Drawing.Size(127, 22)
        Me.txtNewCar.TabIndex = 2
        '
        'lstManageCars
        '
        Me.lstManageCars.FormattingEnabled = True
        Me.lstManageCars.ItemHeight = 16
        Me.lstManageCars.Location = New System.Drawing.Point(36, 43)
        Me.lstManageCars.Name = "lstManageCars"
        Me.lstManageCars.Size = New System.Drawing.Size(120, 84)
        Me.lstManageCars.TabIndex = 1
        '
        'TabPage3
        '
        Me.TabPage3.Controls.Add(Me.btnGenerate)
        Me.TabPage3.Controls.Add(Me.lstNumbers)
        Me.TabPage3.Controls.Add(Me.Label4)
        Me.TabPage3.Controls.Add(Me.Label3)
        Me.TabPage3.Controls.Add(Me.txtNum2)
        Me.TabPage3.Controls.Add(Me.txtNum1)
        Me.TabPage3.Location = New System.Drawing.Point(4, 25)
        Me.TabPage3.Name = "TabPage3"
        Me.TabPage3.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage3.Size = New System.Drawing.Size(568, 324)
        Me.TabPage3.TabIndex = 2
        Me.TabPage3.Text = "Number List Program"
        Me.TabPage3.UseVisualStyleBackColor = True
        '
        'btnGenerate
        '
        Me.btnGenerate.Location = New System.Drawing.Point(216, 185)
        Me.btnGenerate.Name = "btnGenerate"
        Me.btnGenerate.Size = New System.Drawing.Size(94, 23)
        Me.btnGenerate.TabIndex = 5
        Me.btnGenerate.Text = "Generate"
        Me.btnGenerate.UseVisualStyleBackColor = True
        '
        'lstNumbers
        '
        Me.lstNumbers.FormattingEnabled = True
        Me.lstNumbers.ItemHeight = 16
        Me.lstNumbers.Location = New System.Drawing.Point(345, 37)
        Me.lstNumbers.Name = "lstNumbers"
        Me.lstNumbers.Size = New System.Drawing.Size(130, 100)
        Me.lstNumbers.TabIndex = 4
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(44, 102)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(105, 16)
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "Enter Number 2: "
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(44, 47)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(105, 16)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Enter Number 1: "
        '
        'txtNum2
        '
        Me.txtNum2.Location = New System.Drawing.Point(155, 99)
        Me.txtNum2.Name = "txtNum2"
        Me.txtNum2.Size = New System.Drawing.Size(100, 22)
        Me.txtNum2.TabIndex = 1
        '
        'txtNum1
        '
        Me.txtNum1.Location = New System.Drawing.Point(155, 44)
        Me.txtNum1.Name = "txtNum1"
        Me.txtNum1.Size = New System.Drawing.Size(100, 22)
        Me.txtNum1.TabIndex = 0
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(197, 96)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(102, 16)
        Me.Label5.TabIndex = 8
        Me.Label5.Text = "Enter Car Price: "
        '
        'txtNewPrice
        '
        Me.txtNewPrice.Location = New System.Drawing.Point(311, 93)
        Me.txtNewPrice.Name = "txtNewPrice"
        Me.txtNewPrice.Size = New System.Drawing.Size(127, 22)
        Me.txtNewPrice.TabIndex = 7
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(572, 350)
        Me.Controls.Add(Me.TabControl1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.TabControl1.ResumeLayout(False)
        Me.TabPage1.ResumeLayout(False)
        Me.TabPage1.PerformLayout()
        Me.TabPage2.ResumeLayout(False)
        Me.TabPage2.PerformLayout()
        Me.TabPage3.ResumeLayout(False)
        Me.TabPage3.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents TabControl1 As TabControl
    Friend WithEvents TabPage1 As TabPage
    Friend WithEvents TabPage2 As TabPage
    Friend WithEvents lstRentalCars As ListBox
    Friend WithEvents TabPage3 As TabPage
    Friend WithEvents Label1 As Label
    Friend WithEvents txtRentalDays As TextBox
    Friend WithEvents lblRentalResult As Label
    Friend WithEvents btnCalculate As Button
    Friend WithEvents lstManageCars As ListBox
    Friend WithEvents Label2 As Label
    Friend WithEvents btnCountCars As Button
    Friend WithEvents btnDeleteCar As Button
    Friend WithEvents btnAddCar As Button
    Friend WithEvents txtNewCar As TextBox
    Friend WithEvents txtNum2 As TextBox
    Friend WithEvents txtNum1 As TextBox
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents btnGenerate As Button
    Friend WithEvents lstNumbers As ListBox
    Friend WithEvents Label5 As Label
    Friend WithEvents txtNewPrice As TextBox
End Class
