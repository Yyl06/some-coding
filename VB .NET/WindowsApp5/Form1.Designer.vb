<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip()
        Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.NextCustomerToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ProcessToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.CalculatePriceToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ViewSummaryToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.HelpToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.AboutToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.CheckBoxKembung = New System.Windows.Forms.CheckBox()
        Me.CheckBoxKerisi = New System.Windows.Forms.CheckBox()
        Me.CheckBoxSiakap = New System.Windows.Forms.CheckBox()
        Me.TextBoxKembung = New System.Windows.Forms.TextBox()
        Me.TextBoxKerisi = New System.Windows.Forms.TextBox()
        Me.TextBoxSiakap = New System.Windows.Forms.TextBox()
        Me.CheckBoxCleanKembung = New System.Windows.Forms.CheckBox()
        Me.CheckBoxCleanKerisi = New System.Windows.Forms.CheckBox()
        Me.CheckBoxCleanSiakap = New System.Windows.Forms.CheckBox()
        Me.MenuStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'MenuStrip1
        '
        Me.MenuStrip1.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem, Me.ProcessToolStripMenuItem, Me.HelpToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Size = New System.Drawing.Size(482, 28)
        Me.MenuStrip1.TabIndex = 0
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'FileToolStripMenuItem
        '
        Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.NextCustomerToolStripMenuItem, Me.ExitToolStripMenuItem})
        Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
        Me.FileToolStripMenuItem.Size = New System.Drawing.Size(46, 24)
        Me.FileToolStripMenuItem.Text = "File"
        '
        'NextCustomerToolStripMenuItem
        '
        Me.NextCustomerToolStripMenuItem.Name = "NextCustomerToolStripMenuItem"
        Me.NextCustomerToolStripMenuItem.Size = New System.Drawing.Size(190, 26)
        Me.NextCustomerToolStripMenuItem.Text = "Next Customer"
        '
        'ExitToolStripMenuItem
        '
        Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
        Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(190, 26)
        Me.ExitToolStripMenuItem.Text = "Exit"
        '
        'ProcessToolStripMenuItem
        '
        Me.ProcessToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.CalculatePriceToolStripMenuItem, Me.ViewSummaryToolStripMenuItem})
        Me.ProcessToolStripMenuItem.Name = "ProcessToolStripMenuItem"
        Me.ProcessToolStripMenuItem.Size = New System.Drawing.Size(72, 24)
        Me.ProcessToolStripMenuItem.Text = "Process"
        '
        'CalculatePriceToolStripMenuItem
        '
        Me.CalculatePriceToolStripMenuItem.Name = "CalculatePriceToolStripMenuItem"
        Me.CalculatePriceToolStripMenuItem.Size = New System.Drawing.Size(190, 26)
        Me.CalculatePriceToolStripMenuItem.Text = "Calculate Price"
        '
        'ViewSummaryToolStripMenuItem
        '
        Me.ViewSummaryToolStripMenuItem.Name = "ViewSummaryToolStripMenuItem"
        Me.ViewSummaryToolStripMenuItem.Size = New System.Drawing.Size(190, 26)
        Me.ViewSummaryToolStripMenuItem.Text = "View Summary"
        '
        'HelpToolStripMenuItem
        '
        Me.HelpToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.AboutToolStripMenuItem})
        Me.HelpToolStripMenuItem.Name = "HelpToolStripMenuItem"
        Me.HelpToolStripMenuItem.Size = New System.Drawing.Size(55, 24)
        Me.HelpToolStripMenuItem.Text = "Help"
        '
        'AboutToolStripMenuItem
        '
        Me.AboutToolStripMenuItem.Name = "AboutToolStripMenuItem"
        Me.AboutToolStripMenuItem.Size = New System.Drawing.Size(133, 26)
        Me.AboutToolStripMenuItem.Text = "About"
        '
        'CheckBoxKembung
        '
        Me.CheckBoxKembung.AutoSize = True
        Me.CheckBoxKembung.Location = New System.Drawing.Point(94, 76)
        Me.CheckBoxKembung.Name = "CheckBoxKembung"
        Me.CheckBoxKembung.Size = New System.Drawing.Size(86, 20)
        Me.CheckBoxKembung.TabIndex = 1
        Me.CheckBoxKembung.Text = "Kembung"
        Me.CheckBoxKembung.UseVisualStyleBackColor = True
        '
        'CheckBoxKerisi
        '
        Me.CheckBoxKerisi.AutoSize = True
        Me.CheckBoxKerisi.Location = New System.Drawing.Point(94, 121)
        Me.CheckBoxKerisi.Name = "CheckBoxKerisi"
        Me.CheckBoxKerisi.Size = New System.Drawing.Size(62, 20)
        Me.CheckBoxKerisi.TabIndex = 2
        Me.CheckBoxKerisi.Text = "Kerisi"
        Me.CheckBoxKerisi.UseVisualStyleBackColor = True
        '
        'CheckBoxSiakap
        '
        Me.CheckBoxSiakap.AutoSize = True
        Me.CheckBoxSiakap.Location = New System.Drawing.Point(94, 170)
        Me.CheckBoxSiakap.Name = "CheckBoxSiakap"
        Me.CheckBoxSiakap.Size = New System.Drawing.Size(72, 20)
        Me.CheckBoxSiakap.TabIndex = 3
        Me.CheckBoxSiakap.Text = "Siakap"
        Me.CheckBoxSiakap.UseVisualStyleBackColor = True
        '
        'TextBoxKembung
        '
        Me.TextBoxKembung.Location = New System.Drawing.Point(186, 74)
        Me.TextBoxKembung.Name = "TextBoxKembung"
        Me.TextBoxKembung.Size = New System.Drawing.Size(125, 22)
        Me.TextBoxKembung.TabIndex = 4
        '
        'TextBoxKerisi
        '
        Me.TextBoxKerisi.Location = New System.Drawing.Point(162, 119)
        Me.TextBoxKerisi.Name = "TextBoxKerisi"
        Me.TextBoxKerisi.Size = New System.Drawing.Size(125, 22)
        Me.TextBoxKerisi.TabIndex = 5
        '
        'TextBoxSiakap
        '
        Me.TextBoxSiakap.Location = New System.Drawing.Point(172, 168)
        Me.TextBoxSiakap.Name = "TextBoxSiakap"
        Me.TextBoxSiakap.Size = New System.Drawing.Size(125, 22)
        Me.TextBoxSiakap.TabIndex = 6
        '
        'CheckBoxCleanKembung
        '
        Me.CheckBoxCleanKembung.AutoSize = True
        Me.CheckBoxCleanKembung.Location = New System.Drawing.Point(328, 76)
        Me.CheckBoxCleanKembung.Name = "CheckBoxCleanKembung"
        Me.CheckBoxCleanKembung.Size = New System.Drawing.Size(64, 20)
        Me.CheckBoxCleanKembung.TabIndex = 7
        Me.CheckBoxCleanKembung.Text = "Clean"
        Me.CheckBoxCleanKembung.UseVisualStyleBackColor = True
        '
        'CheckBoxCleanKerisi
        '
        Me.CheckBoxCleanKerisi.AutoSize = True
        Me.CheckBoxCleanKerisi.Location = New System.Drawing.Point(328, 121)
        Me.CheckBoxCleanKerisi.Name = "CheckBoxCleanKerisi"
        Me.CheckBoxCleanKerisi.Size = New System.Drawing.Size(64, 20)
        Me.CheckBoxCleanKerisi.TabIndex = 8
        Me.CheckBoxCleanKerisi.Text = "Clean"
        Me.CheckBoxCleanKerisi.UseVisualStyleBackColor = True
        '
        'CheckBoxCleanSiakap
        '
        Me.CheckBoxCleanSiakap.AutoSize = True
        Me.CheckBoxCleanSiakap.Location = New System.Drawing.Point(328, 170)
        Me.CheckBoxCleanSiakap.Name = "CheckBoxCleanSiakap"
        Me.CheckBoxCleanSiakap.Size = New System.Drawing.Size(64, 20)
        Me.CheckBoxCleanSiakap.TabIndex = 9
        Me.CheckBoxCleanSiakap.Text = "Clean"
        Me.CheckBoxCleanSiakap.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(482, 263)
        Me.Controls.Add(Me.CheckBoxCleanSiakap)
        Me.Controls.Add(Me.CheckBoxCleanKerisi)
        Me.Controls.Add(Me.CheckBoxCleanKembung)
        Me.Controls.Add(Me.TextBoxSiakap)
        Me.Controls.Add(Me.TextBoxKerisi)
        Me.Controls.Add(Me.TextBoxKembung)
        Me.Controls.Add(Me.CheckBoxSiakap)
        Me.Controls.Add(Me.CheckBoxKerisi)
        Me.Controls.Add(Me.CheckBoxKembung)
        Me.Controls.Add(Me.MenuStrip1)
        Me.MainMenuStrip = Me.MenuStrip1
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents MenuStrip1 As MenuStrip
    Friend WithEvents FileToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents NextCustomerToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents ExitToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents ProcessToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents CalculatePriceToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents ViewSummaryToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents HelpToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents AboutToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents CheckBoxKembung As CheckBox
    Friend WithEvents CheckBoxKerisi As CheckBox
    Friend WithEvents CheckBoxSiakap As CheckBox
    Friend WithEvents TextBoxKembung As TextBox
    Friend WithEvents TextBoxKerisi As TextBox
    Friend WithEvents TextBoxSiakap As TextBox
    Friend WithEvents CheckBoxCleanKembung As CheckBox
    Friend WithEvents CheckBoxCleanKerisi As CheckBox
    Friend WithEvents CheckBoxCleanSiakap As CheckBox
End Class
