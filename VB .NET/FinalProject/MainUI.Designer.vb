<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MainUI
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
        Me.btnCashier = New System.Windows.Forms.Button()
        Me.btnTransactions = New System.Windows.Forms.Button()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.btnReport = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.btnLogout = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btnCashier
        '
        Me.btnCashier.Location = New System.Drawing.Point(142, 99)
        Me.btnCashier.Name = "btnCashier"
        Me.btnCashier.Size = New System.Drawing.Size(146, 66)
        Me.btnCashier.TabIndex = 0
        Me.btnCashier.Text = "Cashier Main System"
        Me.btnCashier.UseVisualStyleBackColor = True
        '
        'btnTransactions
        '
        Me.btnTransactions.Location = New System.Drawing.Point(381, 99)
        Me.btnTransactions.Name = "btnTransactions"
        Me.btnTransactions.Size = New System.Drawing.Size(146, 66)
        Me.btnTransactions.TabIndex = 1
        Me.btnTransactions.Text = "View Receipt History"
        Me.btnTransactions.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(381, 251)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(146, 66)
        Me.btnExit.TabIndex = 2
        Me.btnExit.Text = "Exit (Close Program)"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'btnReport
        '
        Me.btnReport.Location = New System.Drawing.Point(142, 251)
        Me.btnReport.Name = "btnReport"
        Me.btnReport.Size = New System.Drawing.Size(146, 66)
        Me.btnReport.TabIndex = 3
        Me.btnReport.Text = "Daily Sales Report"
        Me.btnReport.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(303, 38)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(60, 16)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "Choose: "
        '
        'btnLogout
        '
        Me.btnLogout.Location = New System.Drawing.Point(561, 385)
        Me.btnLogout.Name = "btnLogout"
        Me.btnLogout.Size = New System.Drawing.Size(146, 66)
        Me.btnLogout.TabIndex = 5
        Me.btnLogout.Text = "Logout"
        Me.btnLogout.UseVisualStyleBackColor = True
        '
        'MainUI
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(705, 450)
        Me.Controls.Add(Me.btnLogout)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btnReport)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnTransactions)
        Me.Controls.Add(Me.btnCashier)
        Me.Name = "MainUI"
        Me.Text = "Cashier System"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents btnCashier As Button
    Friend WithEvents btnTransactions As Button
    Friend WithEvents btnExit As Button
    Friend WithEvents btnReport As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents btnLogout As Button
End Class
